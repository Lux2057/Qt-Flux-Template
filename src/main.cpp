#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSharedPointer>

#include "action/actionprovider.h"
#include "lib/dispatcher.h"
#include "store/mainstore.h"


using namespace flux_qt;

void qml_register() {
    Dispatcher::instance().registerStore(QSharedPointer<Store>(&MainStore::instance(),
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

}

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);

    QCoreApplication::setApplicationName("Qt-Flux-Template");

    qml_register();

    QQmlApplicationEngine engine;

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    const int ret = app.exec();

    return ret;
}
