#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/NavigationPane>
#include <bb/cascades/ActionItem>
#include <bb/cascades/Page>
#include <bb/cascades/Button>
#include <bb/cascades/ListView>
#include <bb/cascades/Container>

#include <bb/pim/account/Provider>
#include <bb/pim/message/Message>
#include <bb/pim/message/MessageBuilder>
#include <bb/pim/message/MessageContact>
#include <bb/pim/message/MessageSearchFilter>

#include "ParticipantsListItemProvider.h"

using namespace bb::cascades;
using namespace bb::pim::account;
using namespace bb::pim::message;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
        QObject(app),
        m_mainScreen(NULL)
{
    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///Introduction.qml").parent(this);

    // Create root object for the UI
    m_navPane = qml->createRootObject<NavigationPane>();

    ActionItem* emailSetup = m_navPane->findChild<ActionItem*>("setupEmail");
    connect(emailSetup, SIGNAL( triggered() ), this, SLOT( launchEmailSetup() ));

    app->setScene(m_navPane);
}

void ApplicationUI::launchEmailSetup()
{
	if(!m_mainScreen)
	{
		m_mainScreen = new MainScreen();
	}
	// now push it!
	m_mainScreen->show();
}

void ApplicationUI::cancelEmailSetup()
{
	//m_navPane->pop();
}

ApplicationUI::~ApplicationUI()
{
}
