/*
 * MessageListener.cpp
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#include "MessageListener.h"

namespace ooh {

MessageListener::MessageListener() :
	QObject(),
	m_messageDeleted(false)
{
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(checkMessageExists()));
}

void MessageListener::checkMessageExists()
{
	bb::pim::message::MessageSearchFilter filter;
	filter.setAccountId(m_ak);

	QList<bb::pim::message::MessageFolder> folders = m_messageService.folders(m_ak);
	bb::pim::message::MessageFolder sentFolder;
	for(int i = 0; i < folders.size(); ++i)
	{
	 if(folders[i].type() == bb::pim::message::MessageFolder::Sent)
	 {
		 sentFolder = folders[i];
		 break;
	  }
	}

	filter.setFolderId(sentFolder.id());

	filter.addSearchCriteria(bb::pim::message::SearchFilterCriteria::Subject, "Test Subject ");

	QList<bb::pim::message::Message> messagesToDelete = m_messageService.searchLocal(m_ak, filter);
	messagesToDelete.append(m_messageService.searchRemote(m_ak, filter));
	for(int i = 0; i < messagesToDelete.size(); ++i)
	{
		m_timer.stop();
		m_messageDeleted = true;
		m_messageService.remove(m_ak, messagesToDelete[i].id());
		m_messageService.remove(m_ak, m_msg.id());
	}
}

void MessageListener::messageUpdate(bb::pim::account::AccountKey ak,
		bb::pim::message::ConversationKey ck,
		bb::pim::message::MessageKey mk,
		bb::pim::message::MessageUpdate mu)
{
	if(ck == m_ck && mk == m_mk && m_ak == ak)
	{
		m_msg.apply(mu);
		if(m_msg.isSent())
		{
			if(!m_timer.isActive() && !m_messageDeleted)
			{
				m_timer.setSingleShot(false);
				m_timer.setInterval(3000);
				m_timer.start();
			}
		}
	}
}
} /* namespace ooh */
