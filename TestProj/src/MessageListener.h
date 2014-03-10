/*
 * MessageListener.h
 *
 *  Created on: Apr 20, 2013
 *      Author: eghantous
 */

#ifndef MESSAGELISTENER_H_
#define MESSAGELISTENER_H_

#include <QObject>
#include <QTimer>
#include <bb/pim/account/Provider>
#include <bb/pim/message/Message>
#include <bb/pim/message/MessageBuilder>
#include <bb/pim/message/MessageContact>
#include <bb/pim/message/MessageSearchFilter>
#include <bb/pim/message/MessageService>
#include <bb/pim/account/Account>

namespace ooh {

class MessageListener : public QObject
{
     Q_OBJECT

public:
     MessageListener();

     void setAk(bb::pim::account::AccountKey ak)
     {
    	 m_ak = ak;
     }
     void setMk(bb::pim::message::MessageKey mk)
     {
         m_mk = mk;
     }

     void setCk(bb::pim::message::ConversationKey ck)
     {
         m_ck = ck;
     }

     void setMsg(bb::pim::message::Message msg)
     {
         m_msg = msg;
     }

     bool isMessageDeleted() const
     {
    	 return m_messageDeleted;
     }

     virtual ~MessageListener()
     {
         qDebug() << "Going down!";
     }
private slots:

 	 void checkMessageExists();
     void messageUpdate(bb::pim::account::AccountKey ak, bb::pim::message::ConversationKey ck, bb::pim::message::MessageKey mk, bb::pim::message::MessageUpdate mu);


private:

     bb::pim::account::AccountKey m_ak;
     bb::pim::message::MessageKey m_mk;
     bb::pim::message::ConversationKey m_ck;
     bb::pim::message::Message m_msg;
     bb::pim::message::MessageService m_messageService;
     QTimer m_timer;
     bool m_messageDeleted;

};

} /* namespace ooh */
#endif /* MESSAGELISTENER_H_ */
