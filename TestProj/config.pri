# Auto-generated by IDE. Any changes made by user will be lost!
BASEDIR =  $$quote($$_PRO_FILE_PWD_)

device {
    CONFIG(debug, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/ExclusionListItemProvider.cpp) \
                 $$quote($$BASEDIR/src/ExclustionEmailListItem.cpp) \
                 $$quote($$BASEDIR/src/MainScreen.cpp) \
                 $$quote($$BASEDIR/src/MessageListener.cpp) \
                 $$quote($$BASEDIR/src/Participant.cpp) \
                 $$quote($$BASEDIR/src/ParticipantListItem.cpp) \
                 $$quote($$BASEDIR/src/ParticipantSheet.cpp) \
                 $$quote($$BASEDIR/src/ParticipantsListItemProvider.cpp) \
                 $$quote($$BASEDIR/src/applicationui.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/ExclusionListItemProvider.h) \
                 $$quote($$BASEDIR/src/ExclustionEmailListItem.h) \
                 $$quote($$BASEDIR/src/MainScreen.h) \
                 $$quote($$BASEDIR/src/MessageListener.h) \
                 $$quote($$BASEDIR/src/Participant.h) \
                 $$quote($$BASEDIR/src/ParticipantListItem.h) \
                 $$quote($$BASEDIR/src/ParticipantSheet.h) \
                 $$quote($$BASEDIR/src/ParticipantsListItemProvider.h) \
                 $$quote($$BASEDIR/src/applicationui.hpp)
    }

    CONFIG(release, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/ExclusionListItemProvider.cpp) \
                 $$quote($$BASEDIR/src/ExclustionEmailListItem.cpp) \
                 $$quote($$BASEDIR/src/MainScreen.cpp) \
                 $$quote($$BASEDIR/src/MessageListener.cpp) \
                 $$quote($$BASEDIR/src/Participant.cpp) \
                 $$quote($$BASEDIR/src/ParticipantListItem.cpp) \
                 $$quote($$BASEDIR/src/ParticipantSheet.cpp) \
                 $$quote($$BASEDIR/src/ParticipantsListItemProvider.cpp) \
                 $$quote($$BASEDIR/src/applicationui.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/ExclusionListItemProvider.h) \
                 $$quote($$BASEDIR/src/ExclustionEmailListItem.h) \
                 $$quote($$BASEDIR/src/MainScreen.h) \
                 $$quote($$BASEDIR/src/MessageListener.h) \
                 $$quote($$BASEDIR/src/Participant.h) \
                 $$quote($$BASEDIR/src/ParticipantListItem.h) \
                 $$quote($$BASEDIR/src/ParticipantSheet.h) \
                 $$quote($$BASEDIR/src/ParticipantsListItemProvider.h) \
                 $$quote($$BASEDIR/src/applicationui.hpp)
    }
}

simulator {
    CONFIG(debug, debug|release) {
        SOURCES +=  $$quote($$BASEDIR/src/ExclusionListItemProvider.cpp) \
                 $$quote($$BASEDIR/src/ExclustionEmailListItem.cpp) \
                 $$quote($$BASEDIR/src/MainScreen.cpp) \
                 $$quote($$BASEDIR/src/MessageListener.cpp) \
                 $$quote($$BASEDIR/src/Participant.cpp) \
                 $$quote($$BASEDIR/src/ParticipantListItem.cpp) \
                 $$quote($$BASEDIR/src/ParticipantSheet.cpp) \
                 $$quote($$BASEDIR/src/ParticipantsListItemProvider.cpp) \
                 $$quote($$BASEDIR/src/applicationui.cpp) \
                 $$quote($$BASEDIR/src/main.cpp)

        HEADERS +=  $$quote($$BASEDIR/src/ExclusionListItemProvider.h) \
                 $$quote($$BASEDIR/src/ExclustionEmailListItem.h) \
                 $$quote($$BASEDIR/src/MainScreen.h) \
                 $$quote($$BASEDIR/src/MessageListener.h) \
                 $$quote($$BASEDIR/src/Participant.h) \
                 $$quote($$BASEDIR/src/ParticipantListItem.h) \
                 $$quote($$BASEDIR/src/ParticipantSheet.h) \
                 $$quote($$BASEDIR/src/ParticipantsListItemProvider.h) \
                 $$quote($$BASEDIR/src/applicationui.hpp)
    }
}

INCLUDEPATH +=  $$quote($$BASEDIR/src)

CONFIG += precompile_header

PRECOMPILED_HEADER =  $$quote($$BASEDIR/precompiled.h)

lupdate_inclusion {
    SOURCES +=  $$quote($$BASEDIR/../src/*.c) \
             $$quote($$BASEDIR/../src/*.c++) \
             $$quote($$BASEDIR/../src/*.cc) \
             $$quote($$BASEDIR/../src/*.cpp) \
             $$quote($$BASEDIR/../src/*.cxx) \
             $$quote($$BASEDIR/../assets/*.qml) \
             $$quote($$BASEDIR/../assets/*.js) \
             $$quote($$BASEDIR/../assets/*.qs)

    HEADERS +=  $$quote($$BASEDIR/../src/*.h) \
             $$quote($$BASEDIR/../src/*.h++) \
             $$quote($$BASEDIR/../src/*.hh) \
             $$quote($$BASEDIR/../src/*.hpp) \
             $$quote($$BASEDIR/../src/*.hxx)
}

TRANSLATIONS =  $$quote($${TARGET}.ts)