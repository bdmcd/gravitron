#include "wormhole.h"
#include <math.h>
#include <QTimer>

static qreal s_animationDuration = 100;

Wormhole::Wormhole(QQuickItem *parent) : QQuickItem(parent), _goingThrough1(false), _goingThrough2(false)
{
}

Wormhole::~Wormhole()
{
}

void Wormhole::hitWormhole(Player *player, Planet *collisionPlanet, Planet *connectingPlanet, qreal angle)
{
//    qreal vx = player->vx();
//    qreal vy = player->vy();
//    qreal v = sqrt(vx*vx + vy*vy);

//    vx = v*cos(angle);
//    vy = v*sin(angle);

//    player->setVx(vx);
//    player->setVy(vy);
    player->setCenterX(connectingPlanet->centerX());
    player->setCenterY(connectingPlanet->centerY());
}

void Wormhole::updateFrame(Player *player)
{
    if (player->intersects(_planet1))
    {
        if (!_goingThrough1)
        {
            hitWormhole(player, _planet1, _planet2, _angle2);
            _goingThrough2 = true;
        }
    }
    else
        _goingThrough1 = false;

    if (player->intersects(_planet2))
    {
        if (!_goingThrough2)
        {
            hitWormhole(player, _planet2, _planet1, _angle1);
            _goingThrough1 = true;
        }
    }
    else
        _goingThrough2 = false;
}

void Wormhole::setAngle1(qreal angle)
{
    _angle1 = angle;
    emit angle1Changed();
}
void Wormhole::setAngle2(qreal angle)
{
    _angle2 = angle;
    emit angle2Changed();
}

void Wormhole::setPlanet1(Planet *p)
{
    _planet1 = p;
    emit planet1Changed();
}
void Wormhole::setPlanet2(Planet *p)
{
    _planet2 = p;
    emit planet2Changed();
}


qreal Wormhole::angle1() { return _angle1; }
qreal Wormhole::angle2() { return _angle2; }
Planet* Wormhole::planet1() { return _planet1; }
Planet* Wormhole::planet2() { return _planet2; }
