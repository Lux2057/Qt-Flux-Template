#include "LocalizationService.h"


void LocalizationService::setLanguage(QString code) {
	const QString baseName = "Localization_" + code + ".qm";

	if (!_translator.load(":/Localization/" + baseName))
		return;

	qApp->installTranslator(&_translator);
	_engine->retranslate();

	emit languageChanged();
}

QString LocalizationService::MAIN_WINDOW_TITLE_LT() {
    return QObject::tr("Qt FLUX template");
}

QString LocalizationService::CHOOSE_LANGUAGE_LT() {
    return QObject::tr("Choose language");
}
