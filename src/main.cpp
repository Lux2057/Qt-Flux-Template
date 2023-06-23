#include <functional>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include <QSharedPointer>

#include <store/MainStore.h>
#include "action/ActionProvider.h"
#include "action/NavigationActionProvider.h"
#include "lib/dispatcher.h"
#include "Providers/QmlConstantsProvider.h"
#include "Services/LocalizationService.h"
#include "store/NavigationStore.h"
#include "Controls/ExampleControl.h"


using namespace flux_qt;

void qml_register() {
	Dispatcher::instance().registerStore(QSharedPointer<Store>(&MainStore::instance(),
	                                                           [](Store*) {}));
	Dispatcher::instance().registerStore(QSharedPointer<Store>(&NavigationStore::instance(),
	                                                           [](Store*) {}));

	qmlRegisterSingletonType<ActionProvider>("Flux", 1, 0, "ActionProvider",
	                                         [](QQmlEngine* engine, QJSEngine* scriptEngine) -> QObject* {
		                                         Q_UNUSED(engine)
		                                         Q_UNUSED(scriptEngine)

		                                         QQmlEngine::setObjectOwnership(&ActionProvider::instance(), QQmlEngine::CppOwnership);
		                                         return &ActionProvider::instance();
	                                         });

	qmlRegisterSingletonType<MainStore>("Flux", 1, 0, "MainStore",
	                                    [](QQmlEngine* engine, QJSEngine* scriptEngine) -> QObject* {
		                                    Q_UNUSED(engine)
		                                    Q_UNUSED(scriptEngine)

		                                    QQmlEngine::setObjectOwnership(&MainStore::instance(), QQmlEngine::CppOwnership);
		                                    return &MainStore::instance();
	                                    });

	qmlRegisterSingletonType<NavigationActionProvider>("Flux", 1, 0, "NavigationActionProvider",
	                                                   [](QQmlEngine* engine, QJSEngine* scriptEngine) -> QObject* {
		                                                   Q_UNUSED(engine)
		                                                   Q_UNUSED(scriptEngine)

		                                                   QQmlEngine::setObjectOwnership(&NavigationActionProvider::instance(), QQmlEngine::CppOwnership);
		                                                   return &NavigationActionProvider::instance();
	                                                   });

	qmlRegisterSingletonType<NavigationStore>("Flux", 1, 0, "NavigationStore",
	                                          [](QQmlEngine* engine, QJSEngine* scriptEngine) -> QObject* {
		                                          Q_UNUSED(engine)
		                                          Q_UNUSED(scriptEngine)

		                                          QQmlEngine::setObjectOwnership(&NavigationStore::instance(), QQmlEngine::CppOwnership);
		                                          return &NavigationStore::instance();
	                                          });

	qmlRegisterSingletonType<QmlConstantsProvider>("QmlProviders", 1, 0, "Constants",
	                                               [](QQmlEngine* engine, QJSEngine* scriptEngine) -> QObject* {
		                                               Q_UNUSED(engine)
		                                               Q_UNUSED(scriptEngine)

		                                               QQmlEngine::setObjectOwnership(&QmlConstantsProvider::instance(), QQmlEngine::CppOwnership);
		                                               return &QmlConstantsProvider::instance();
	                                               });

	qmlRegisterType<ExampleControl>("CppControls", 1, 0, "ExampleControl");

}

int main(int argc, char* argv[]) {
	QGuiApplication app(argc, argv);

	QCoreApplication::setApplicationName("Qt-Flux-Template");

	qml_register();

	QQmlApplicationEngine engine;
	LocalizationService localizationService(&engine);
	engine.rootContext()->setContextProperty("LocalizationService", &localizationService);
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	const int ret = app.exec();

	return ret;
}
