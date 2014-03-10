/*
 * Participant.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#include "Participant.h"

namespace ooh {

Participant::~Participant() {
	// TODO Auto-generated destructor stub
}

bool Participant::isExcluded(QString email)
	{
		for(int i = 0; i < m_exclusionList.size(); ++i)
		{
			bool sameEmail = !m_exclusionList[i].compare(email, Qt::CaseInsensitive);
			if(sameEmail)
			{
				return true;
			}
		}
		return false;
	}
} /* namespace ooh */
