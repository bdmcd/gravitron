#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>
#include <QScreen>
#include "game.h"
#include "globals.h"
#include "levelloader.h"

void registerTypes() {
    qmlRegisterType<Planet>("planet", 1, 0, "Planet");
    qmlRegisterType<MovingPlanet>("movingPlanet", 1, 0, "MovingPlanet");
    qmlRegisterType<Player>("player", 1, 0, "Player");
    qmlRegisterType<Game>("game", 1, 0, "Game");
    qmlRegisterType<Target>("target", 1, 0, "Target");
    qmlRegisterType<Level>("level", 1, 0, "Level");
    qmlRegisterType<LevelLoader>("levelLoader", 1, 0, "LevelLoader");
    qmlRegisterType<Compass>("compass", 1, 0, "Compass");
    qmlRegisterType<Bonus>("bonus", 1, 0, "Bonus");
    qmlRegisterType<Wormhole>("wormhole", 1, 0, "Wormhole");
}

int main(int argc, char *argv[]) {
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    qsrand(QTime::currentTime().msec());
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    registerTypes();
    Globals globals;
    globals.setPlatformName(app.platformName());
    engine.rootContext()->setContextProperty("Globals", &globals);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
