QT += quick quickcontrols2 multimedia

CONFIG += c++17 embed_translations

DEFINES += QT_DEPRECATED_WARNINGSs

SOURCES += main.cpp \

RESOURCES += qml.qrc \

include(FLUX/FLUX.pri)
include(Constants/Constants.pri)
include(Providers/Providers.pri)
include(Services/Services.pri)
