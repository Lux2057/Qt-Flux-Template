QT += quick quickcontrols2 multimedia

CONFIG += c++17 embed_translations

TRANSLATIONS += \
    Localization/Localization_ru_RU.ts \
    Localization/Localization_en_US.ts \

DEFINES += QT_DEPRECATED_WARNINGSs

SOURCES += main.cpp \

RESOURCES += qml.qrc \

include(FLUX/FLUX.pri)
include(Constants/Constants.pri)
include(Providers/Providers.pri)
include(Services/Services.pri)
include(Controls/Controls.pri)
