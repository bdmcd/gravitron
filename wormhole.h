#ifndef WORMHOLE_H
#define WORMHOLE_H

#include <QQuickItem>
#include "planet.h"
#include "player.h"

class Wormhole : public QQuickItem
{
    Q_OBJECT
public:
    explicit Wormhole(QQuickItem *parent = 0);
    ~Wormhole();

    void updateFrame(Player *player);

    qreal angle1();
    qreal angle2();
    Planet* planet1();
    Planet* planet2();

    void setAngle1(qreal angle);
    void setAngle2(qreal angle);
    void setPlanet1(Planet *p);
    void setPlanet2(Planet *p);

    Q_PROPERTY(qreal angle1 READ angle1 WRITE setAngle1 NOTIFY angle1Changed)
    Q_PROPERTY(qreal angle2 READ angle2 WRITE setAngle2 NOTIFY angle2Changed)
    Q_PROPERTY(Planet* planet1 READ planet1 WRITE setPlanet1 NOTIFY planet1Changed)
    Q_PROPERTY(Planet* planet2 READ planet2 WRITE setPlanet2 NOTIFY planet2Changed)

private:
    Planet *_planet1, *_planet2;
    qreal _angle1, _angle2;
    bool _goingThrough1, _goingThrough2;

    void hitWormhole(Player *player, Planet *collisionPlanet, Planet *connectingPlanet, qreal angle);

signals:
    void angle1Changed();
    void angle2Changed();
    void planet1Changed();
    void planet2Changed();

public slots:
};

#endif // WORMHOLE_H
