/*
 * Participant.h
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#ifndef PARTICIPANT_H_
#define PARTICIPANT_H_
#include <QString>
#include <QStringList>
namespace ooh {

class Participant {
public:
	Participant(QString name, QString email, QStringList exList) :
		m_name(name),
		m_email(email),
		m_exclusionList(exList)
	{

	}

	QString getName() const
	{
		return m_name;
	}

	QString getEmail() const
	{
		return m_email;
	}

	QStringList getExList() const
	{
		return m_exclusionList;
	}

	bool isExcluded(QString email);
	virtual ~Participant();

private:
	QString m_name;
	QString m_email;
	QStringList m_exclusionList;
};

} /* namespace ooh */
#endif /* PARTICIPANT_H_ */
