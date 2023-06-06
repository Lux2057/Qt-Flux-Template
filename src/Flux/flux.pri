INCLUDEPATH += \
    $$PWD

LIBS +=

HEADERS += \
    $$PWD/action/actiontypes.h \
    $$PWD/store/MainStoreImpl.h \
    $$PWD/store/mainstore.h \    
    $$PWD/action/actionprovider.h \
    $$PWD/lib/action.h \
    $$PWD/lib/dispatcher.h \
    $$PWD/lib/middleware.h \
    $$PWD/lib/store.h \


SOURCES += \
    $$PWD/store/MainStoreImpl.cpp \
    $$PWD/store/mainstore.cpp \
    $$PWD/action/actionprovider.cpp \
