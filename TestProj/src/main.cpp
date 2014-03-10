#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include "applicationui.hpp"
#include "MessageListener.h"
#include <QObject>
#include <Qt/qdeclarativedebug.h>
#include <bb/cascades/SceneCover>
#include <bb/cascades/AbstractCover>

using namespace ooh;
using namespace bb::cascades;
using namespace bb::pim::account;
using namespace bb::pim::message;

using namespace bb::cascades;

void redirectedMessageOutput(QtMsgType type, const char *msg) {
	Q_UNUSED(type);
	fprintf(stderr, "%s\n", msg);
}

Q_DECLARE_METATYPE(bb::pim::message::MessageUpdate)

Q_DECL_EXPORT int main(int argc, char **argv) {
	//qInstallMsgHandler(redirectedMessageOutput);

	// The SceneCover is registered so that it can be used in QML
	qmlRegisterType<SceneCover>("bb.cascades", 1, 0, "SceneCoverElias");

	// Since it is not possible to create an instance of the AbstractCover
	// it is registered as an uncreatable type (necessary for accessing
	// Application.cover).
	qmlRegisterUncreatableType<AbstractCover>("bb.cascades", 1, 0, "AbstractCover",
	        "An AbstractCover cannot be created.");

	qRegisterMetaType<bb::pim::message::MessageFolderKey>();
	qRegisterMetaType<bb::pim::message::MessageUpdate>();
     Application app(argc, argv);

     // Initiate, load and install the application translation files.
     QTranslator translator;
     QString locale_string = QLocale().name();
     QString filename = QString("OutOfHat_%1").arg(locale_string);
     if (translator.load(filename, "app/native/qm")) {
         app.installTranslator(&translator);
     }



     /*MessageSearchFilter filter;
     filter.setAccountId(account.id());

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

     filter.addSearchCriteria(SearchFilterCriteria::Subject, "Test
Subject ");

     QList<Message> messagesToDelete =
messageService.searchLocal(account.id(), filter);

     if(messagesToDelete.isEmpty())
     {
         filter.setFolderId(sentFolder.id());
         filter.addSearchCriteria(SearchFilterCriteria::Subject, "Test
Subject ");
         messagesToDelete = messageService.searchLocal(account.id(),
filter);
     }

     for(int i = 0; i < messagesToDelete.size(); ++i)
     {
         messageService.remove(account.id(), messagesToDelete[i].id());
     }
*/
     // Create the Application UI object, this is where the main.qml file
     // is loaded and the application scene is set.
     new ApplicationUI(&app);

     // Enter the application main event loop.
     return Application::exec();
}

//#include "main.moc"
