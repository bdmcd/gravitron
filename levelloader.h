#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include <QObject>

class LevelLoader : public QObject
{
    Q_OBJECT
public:
    explicit LevelLoader(QObject *parent = 0);
    ~LevelLoader();

    Q_INVOKABLE void loadLevel(int levelNumber);

signals:
    void playerLoaded(qreal playerMass);
    void targetLoaded(qreal targetRadius, qreal targetX, qreal targetY);
    void planetLoaded(qreal planetMass, qreal planetX, qreal planetY);
    void movingPlanetLoaded(qreal planetMass, qreal planetX, qreal planetY, qreal planetVX, qreal planetVY);
    void bonusAdded(qreal bonusMass, qreal bonusX, qreal bonusY);
    void wormholeAdded(qreal wormholeX1, qreal wormholeY1, qreal wormholeX2, qreal wormholeY2, qreal wormholeAngle1, qreal wormholeAngle2);

public slots:
};

#endif // LEVELLOADER_H
