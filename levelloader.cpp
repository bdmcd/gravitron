#include "levelloader.h"
#include "QFile"
#include "QJsonDocument"
#include "QJsonArray"
#include "QJsonObject"
#include "QJsonValue"
#include "QDebug"

LevelLoader::LevelLoader(QObject *parent) : QObject(parent)
{
}

LevelLoader::~LevelLoader()
{
}


void LevelLoader::loadLevel(int levelNumber)
{
    QFile file(":/level" + QString::number(levelNumber) + ".json");
    if (!file.open(QIODevice::ReadOnly))
        return;

    QString docStr = file.readAll();

    QJsonObject level = QJsonDocument::fromJson(docStr.toUtf8()).object();

    QJsonObject player = level.take("Player").toObject();
    emit playerLoaded(player.value("mass").toDouble());

    QJsonObject target = level.take("Target").toObject();
    emit targetLoaded(target.value("radius").toDouble(), target.value("x").toDouble(), target.value("y").toDouble());

    QJsonArray planets = level.take("planets").toArray();
    foreach(QJsonValue v, planets)
    {
        QJsonObject planet = v.toObject();
        emit planetLoaded(planet.value("mass").toDouble(), planet.value("x").toDouble(), planet.value("y").toDouble());
    }

    QJsonArray movingPlanets = level.take("moving planets").toArray();
    foreach(QJsonValue v, movingPlanets)
    {
        QJsonObject planet = v.toObject();
        emit movingPlanetLoaded(planet.value("mass").toDouble(), planet.value("x").toDouble(), planet.value("y").toDouble(), planet.value("vx").toDouble(), planet.value("vy").toDouble());
    }

    QJsonArray bonuses = level.take("bonuses").toArray();
    foreach(QJsonValue v, bonuses)
    {
        QJsonObject bonus = v.toObject();
        emit bonusAdded(bonus.value("mass").toDouble(), bonus.value("x").toDouble(), bonus.value("y").toDouble());
    }

    QJsonArray wormholes = level.take("wormholes").toArray();
    foreach(QJsonValue v, wormholes)
    {
        QJsonObject wormhole = v.toObject();
        emit wormholeAdded(wormhole.value("x1").toDouble(), wormhole.value("y1").toDouble(), wormhole.value("x2").toDouble(), wormhole.value("y2").toDouble(), wormhole.value("angle1").toDouble(), wormhole.value("angle2").toDouble());
    }
}
