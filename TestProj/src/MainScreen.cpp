/*
 * MainScreen.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#include "MainScreen.h"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/ActionItem>
#include <bb/cascades/Page>
#include <bb/cascades/Button>
#include <bb/cascades/ListView>
#include <bb/cascades/Container>
#include <bb/cascades/TextField>
#include <bb/cascades/TextArea>
#include <bb/pim/account/Provider>
#include <bb/pim/message/Message>
#include <bb/pim/message/MessageBuilder>
#include <bb/pim/message/MessageContact>
#include <bb/pim/message/MessageSearchFilter>

#include "ParticipantsListItemProvider.h"

namespace ooh {

MainScreen::MainScreen() :
		QObject(),
		m_addParticipantSheet(NULL),
		m_worker(NULL),
		m_cancelled(false)
{
	QmlDocument *qml = QmlDocument::create("asset:///MainPage.qml").parent(this);
	m_mainPage = qml->createRootObject<Sheet>();
	ListView* lv = m_mainPage->findChild<ListView*>("listView");
	lv->setDataModel(&m_participants);
	ParticipantsListItemProvider* p = new ParticipantsListItemProvider();
	lv->setListItemProvider(p);
	Button* b = m_mainPage->findChild<Button*>("addParticipant");
	connect(b, SIGNAL( clicked() ), this, SLOT(handleAddParticipant() ));

	connect(m_mainPage->findChild<ActionItem*>("clearAction"), SIGNAL(triggered()), this, SLOT( handleClearAll()));
	connect(m_mainPage->findChild<ActionItem*>("sendAction"), SIGNAL(triggered()), this, SLOT( handleSend()));

	connect(m_mainPage->findChild<Button*>("cancelWork"), SIGNAL(clicked()), this, SLOT(cancelWork()));
	connect(m_mainPage->findChild<Button*>("closeButton"), SIGNAL(clicked()), this, SLOT(closeSheet()));
}

MainScreen::~MainScreen() {
	// TODO Auto-generated destructor stub
}

void MainScreen::handleAddParticipant()
{
	if(!m_addParticipantSheet)
	{
		m_addParticipantSheet = new ParticipantSheet();
		connect(m_addParticipantSheet, SIGNAL( participantAdded(Participant) ), this, SLOT(handleParticipantAdded(Participant)));
	}
	m_addParticipantSheet->reset();
	m_addParticipantSheet->open();
}

void MainScreen::handleParticipantAdded(Participant p)
{
	QVariantMap map;
	map["name"] = p.getName();
	map["email"] = p.getEmail();
	map["exl"] = p.getExList();

	m_participants << map;
	m_mainPage->setProperty("numParticipants", m_participants.size());
}

void MainScreen::handleClearAll()
{
	m_participants.clear();
	m_mainPage->setProperty("numParticipants", 0);
}
QList<int> MainScreen::randomizeBuyers()
{
	QList<int> order;
	for(int i = 0; i < m_participants.size(); ++i)
	{
		order.append(i);
	}

	unsigned int size = m_participants.size();
	unsigned int i = 0;
	// seed the random number generator with the current time
	QTime time = QTime::currentTime();
	qsrand((uint)time.msec());

	// Use Fisher-Yates to randomly swap indexes
	while(i < size)
	{
		int index = qrand();
		index = index % size;
		int temp = order[index];
		order[index] = order[i];
		order[i] = temp;
		++i;
	}
	return order;
}

bool IsValidPair(Participant& buyer,
  const Participant& receiver)
{
	bool sameEmail = !buyer.getEmail().compare(receiver.getEmail(), Qt::CaseInsensitive);
  return( !sameEmail && !buyer.isExcluded(receiver.getEmail()));
}

void MainScreen::handleSend()
{
	m_cancelled = false;
	m_mainPage->setProperty("workInProgress", true);
	m_worker = new QThread(this);

	 connect(m_worker, SIGNAL(started()), this, SLOT(doSend()));
	 connect(m_worker, SIGNAL(finished()), this, SLOT(workDone()));
	 connect(m_worker, SIGNAL(terminated()), this, SLOT(workDone()));
	 m_worker->start();
}

void MainScreen::doSend()
{
	QList<int> order = randomizeBuyers();
	//QList<Participant> receivers(m_participants.size());

	typedef QPair<Participant, Participant> ParticipantPair;
	QList<ParticipantPair> pairs;

	bool success = false;
	while(!success)
	{
	  bool errorOccurred = false;
	  for(int i = 0; !errorOccurred && i < m_participants.size(); ++i)
	  {
	          // refactor the drafting out into it's own class.  The Input reader
	          // should not know about how drafting occurs
		  	  int j = order[i];

	          Participant buyer(m_participants.value(j)["name"].value<QString>(), m_participants.value(j)["email"].value<QString>(), m_participants.value(j)["exl"].value<QStringList>());
	          Participant receiver(m_participants.value(i)["name"].value<QString>(), m_participants.value(i)["email"].value<QString>(), m_participants.value(i)["exl"].value<QStringList>());
	          if(!IsValidPair(buyer, receiver))
	          {
	            errorOccurred = true;
	          }
	          else
	          {
	        	  pairs.append(ParticipantPair(buyer,receiver));
	          }
	  }

	  if(errorOccurred)
	  {

		  order = randomizeBuyers();
			pairs.clear();
	  }
	  else
	  {
		success = true;
	  }
	}

	AccountService* as = new AccountService();
	Account account = as->defaultAccount(Service::Messages);

	MessageService ms;
	m_subject = m_mainPage->findChild<TextField*>("emailSubject")->text();
	QString body = "<p>" + m_mainPage->findChild<TextArea*>("emailBody")->text() + "</p>";

	for(int i = 0; i < pairs.size(); ++i)
	{
	  QString greeting = "<p>Hi " + pairs[i].first.getName() + "!</p>";
	  QString youGot = "You Received: " + pairs[i].second.getName();
		MessageBuilder* builder = MessageBuilder::create(account.id());
		MessageContact rto = MessageContact(-1,MessageContact::To,pairs[i].first.getName(), pairs[i].first.getEmail());
		QString fullMsg = greeting + body + youGot;
		QByteArray bodyData = fullMsg.toAscii();
		builder->subject(m_subject);
		bool added;
		builder->addRecipient(rto,&added);
		builder->body(MessageBody::Html,bodyData);
		Message message = *builder;

/*
	    connect(&m_messageService, SIGNAL( messageUpdated(bb::pim::account::AccountKey, bb::pim::message::ConversationKey, bb::pim::message::MessageKey, bb::pim::message::MessageUpdate) ),
	            &m_ml,
	            SLOT( messageUpdate(bb::pim::account::AccountKey, bb::pim::message::ConversationKey, bb::pim::message::MessageKey, bb::pim::message::MessageUpdate) ) );
*/


		/*MessageKey mk = */ms.send(account.id(), message);
		/*Message sentMessage = ms.message(account.id(), mk);
		m_ml.setAk(account.id());
		m_ml.setMk(sentMessage.id());
		m_ml.setCk(sentMessage.conversationId());
		m_ml.setMsg(sentMessage);*/
		//********************************************************
	    // Set created root object as the application scene
	    //m_navPane->setBackButtonsVisible(false);
	}

	m_worker->exit();

}

void MainScreen::cancelWork()
{
	m_cancelled = true;
	if(m_worker)
	{
		m_worker->exit();
	}
	else
	{
		workDone();
	}
}

void MainScreen::workDone()
{
	if(m_worker)
	{
		delete m_worker;
		m_worker = NULL;
	}
	if(!m_cancelled)
	{
		AccountService* as = new AccountService();
		Account account = as->defaultAccount(Service::Messages);

		MessageSearchFilter filter;
		filter.setAccountId(account.id());
		MessageService messageService;

		QList<MessageFolder> folders = messageService.folders(account.id());
		MessageFolder sentFolder;
		for(int i = 0; i < folders.size(); ++i)
		{
			if(folders[i].type() == MessageFolder::Sent)
			{
				sentFolder = folders[i];
				break;
			}
		}

		filter.setFolderId(sentFolder.id());
		filter.addSearchCriteria(SearchFilterCriteria::Subject, m_subject);

		QList<Message> messagesToDelete = messageService.searchLocal(account.id(), filter);
		messagesToDelete.append(messageService.searchRemote(account.id(), filter));

		for(int i = 0; i < messagesToDelete.size(); ++i)
		{
			messageService.remove(account.id(), messagesToDelete[i].id());
		}



		m_mainPage->setProperty("allDone", true);
	}
	m_mainPage->setProperty("workInProgress", false);
}

void MainScreen::closeSheet()
{
	handleClearAll();
	m_mainPage->setProperty("allDone", false);
	m_mainPage->close();
}
} /* namespace ooh */
