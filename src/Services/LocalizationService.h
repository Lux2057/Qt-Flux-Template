#ifndef LOCALIZATIONSERVICE_H
#define LOCALIZATIONSERVICE_H

#include <qguiapplication.h>
#include <QQmlApplicationEngine>
#include <qtranslator.h>


class LocalizationService : public QObject
{
	Q_OBJECT

	Q_PROPERTY(QString MAIN_WINDOW_TITLE_LT READ MAIN_WINDOW_TITLE_LT NOTIFY languageChanged)	

    Q_PROPERTY(QString CHOOSE_LANGUAGE_LT READ CHOOSE_LANGUAGE_LT NOTIFY languageChanged)

public:
	explicit LocalizationService(QQmlApplicationEngine* engine, QObject* parent = nullptr) : QObject(parent), _engine(engine) {}

    Q_INVOKABLE void setLanguage(QString code);

	static QString MAIN_WINDOW_TITLE_LT();

    static QString CHOOSE_LANGUAGE_LT();

signals:
	void languageChanged();

private:
	QTranslator _translator;

	QQmlApplicationEngine* _engine;
};


#endif // LOCALIZATIONSERVICE_H
