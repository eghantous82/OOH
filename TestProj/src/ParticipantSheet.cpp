/*
 * ParticipantSheet.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#include "ParticipantSheet.h"
#include "ParticipantSheet.h"
#include <bb/cascades/Sheet>
#include <bb/cascades/Page>
#include <bb/cascades/TextField>
#include <bb/cascades/Button>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/ListView>
#include <QRegExp>
#include "ExclusionListItemProvider.h"

using namespace bb::cascades;

namespace ooh {

ParticipantSheet::ParticipantSheet():
		QObject() {

	QmlDocument *qml = QmlDocument::create("asset:///Participant.qml").parent(this);

	m_sheet = qml->createRootObject<Sheet>();
	connect(m_sheet->content()->findChild<Button*>("cancelButton"), SIGNAL(clicked()), this, SLOT(onCancel()));
	connect(m_sheet->content()->findChild<Button*>("okButton"), SIGNAL(clicked()), this, SLOT(onOK()));
	connect(m_sheet->content()->findChild<Button*>("addExlusion"), SIGNAL(clicked()), this, SLOT(onAddExclusionEmail()));
	connect(m_sheet->content()->findChild<TextField*>("email"), SIGNAL( textChanging(QString) ), this, SLOT( onEmailChanging(QString) ));
	connect(m_sheet->content()->findChild<TextField*>("exEmail"), SIGNAL( textChanging(QString) ), this, SLOT( onExclusionEmailChanging(QString) ));
	ListView* lv = m_sheet->content()->findChild<ListView*>("exList");
	lv->setDataModel(&m_exList);
	ExclusionListItemProvider* p = new ExclusionListItemProvider();
	p->setParent(this);
	lv->setListItemProvider(p);
}

void ParticipantSheet::open()
{
	m_sheet->open();
	m_sheet->content()->findChild<TextField*>("name")->requestFocus();

}

ParticipantSheet::~ParticipantSheet() {
	delete m_sheet;
}

void ParticipantSheet::onCancel()
{
	m_sheet->close();
}

void ParticipantSheet::onOK()
{
	// extract the info and close the sheet
	QString name = m_sheet->content()->findChild<TextField*>("name")->text().trimmed();
	QString email = m_sheet->content()->findChild<TextField*>("email")->text().trimmed();
	QStringList exList;
	for(int i = 0; i < m_exList.size(); ++i)
	{
		exList << m_exList.value(i).trimmed();
	}
	emit participantAdded(Participant(name, email, exList));
	m_sheet->close();
}

void ParticipantSheet::onEmailChanging(QString email)
{
    QRegExp naRegEx("^[_A-Za-z0-9-]+(\\.[_A-Za-z0-9-]+)*@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$");
    bool isValid = naRegEx.exactMatch(email.trimmed());
    m_sheet->setProperty("validEmail", isValid);
}

void ParticipantSheet::onExclusionEmailChanging(QString email)
{
    QRegExp naRegEx("^[_A-Za-z0-9-]+(\\.[_A-Za-z0-9-]+)*@[A-Za-z0-9]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$");
    bool isValid = naRegEx.exactMatch(email.trimmed());
    m_sheet->setProperty("validExEmail", isValid);
}

void ParticipantSheet::onAddExclusionEmail()
{
	m_exList << m_sheet->content()->findChild<TextField*>("exEmail")->text().trimmed();
	m_sheet->content()->findChild<TextField*>("exEmail")->setText("");
}

void ParticipantSheet::reset()
{
	m_sheet->content()->findChild<TextField*>("name")->setText("");
	m_sheet->content()->findChild<TextField*>("email")->setText("");
	m_sheet->content()->findChild<TextField*>("exEmail")->setText("");
	m_exList.clear();
}
} /* namespace ooh */
