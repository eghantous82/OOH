/*
 * MainScreen.h
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#ifndef MAINSCREEN_H_
#define MAINSCREEN_H_
#include <bb/cascades/NavigationPane>
#include <bb/cascades/Sheet>
#include <bb/pim/message/MessageService>
#include <bb/pim/account/AccountService>
#include <QObject>
#include "Participant.h"
#include "ParticipantSheet.h"
using namespace bb::pim::account;
using namespace bb::pim::message;
using namespace bb::cascades;
namespace ooh {

class MainScreen : public QObject {

	Q_OBJECT

public:
	MainScreen();
	virtual ~MainScreen();

	void show()
	{
		m_mainPage->open();
	}
private slots:
	void handleAddParticipant();
	void handleParticipantAdded(Participant p);
	void handleClearAll();
	void handleSend();
	void doSend();
	void cancelWork();
	void workDone();
	void closeSheet();
private:
	QList<int> randomizeBuyers();
	Sheet* m_mainPage;
	ParticipantSheet* m_addParticipantSheet;
	QMapListDataModel m_participants;
	QThread* m_worker;
	bool m_cancelled;
	QString m_subject;
};

} /* namespace ooh */
#endif /* MAINSCREEN_H_ */
