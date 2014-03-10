/*
 * ParticipantSheet.h
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#ifndef PARTICIPANTSHEET_H_
#define PARTICIPANTSHEET_H_
#include <bb/cascades/QListDataModel>
#include "Participant.h"
#include <bb/cascades/Sheet>

namespace ooh {

class ParticipantSheet : public QObject {

	Q_OBJECT

public:
	ParticipantSheet();
	virtual ~ParticipantSheet();
	void reset();
	void open();
signals:
	void participantAdded(Participant p);
private slots:

	void onCancel();
	void onOK();
	void onEmailChanging(QString email);
	void onExclusionEmailChanging(QString email);
	void onAddExclusionEmail();
private:
	bb::cascades::QStringListDataModel m_exList;

	bb::cascades::Sheet* m_sheet;
};

} /* namespace ooh */
#endif /* PARTICIPANTSHEET_H_ */
