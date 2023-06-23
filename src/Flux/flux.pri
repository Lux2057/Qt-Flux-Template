INCLUDEPATH += \
    $$PWD

LIBS +=

HEADERS += \
    $$PWD/action/ActionTypes.h \
    $$PWD/action/NavigationActionProvider.h \
    $$PWD/action/NavigationActionTypes.h \
    $$PWD/store/MainStoreImpl.h \
    $$PWD/store/NavigationStoreImpl.h \
    $$PWD/store/MainStore.h \     \
    $$PWD/store/NavigationStore.h \
    $$PWD/action/ActionProvider.h \
    $$PWD/lib/action.h \
    $$PWD/lib/dispatcher.h \
    $$PWD/lib/middleware.h \
    $$PWD/lib/store.h \


SOURCES += \
    $$PWD/action/NavigationActionProvider.cpp \
    $$PWD/store/MainStoreImpl.cpp \
    $$PWD/store/NavigationStoreImpl.cpp \
    $$PWD/store/MainStore.cpp \
    $$PWD/action/ActionProvider.cpp \
    $$PWD/store/NavigationStore.cpp
