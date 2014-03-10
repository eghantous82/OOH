#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>

#include <bb/pim/message/MessageService>
#include <bb/pim/account/AccountService>

#include "MessageListener.h"
#include "ParticipantSheet.h"
#include "Participant.h"
#include "MainScreen.h"
using namespace ooh;
namespace bb {
	namespace cascades {
		class Application;
		class NavigationPane;
		class Page;
		class ListView;
	}
}

/*!
 * @brief Application object
 *
 *
 */

using namespace bb::pim::account;
using namespace bb::pim::message;
using namespace bb::cascades;
class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI();


private slots:
	void launchEmailSetup();
	void cancelEmailSetup();
private:

    MessageListener m_ml;
    MessageService m_messageService;
    Message m_sentMessage;
    NavigationPane* m_navPane;
    MainScreen* m_mainScreen;
};


#endif /* ApplicationUI_HPP_ */
