#include "movingplanet.h"
#include "math.h"

MovingPlanet::MovingPlanet(QQuickItem *parent) : Planet(parent), _vx(0), _vy(0), _fx(0), _fy(0), _fgx(0), _fgy(0)
{
}

MovingPlanet::~MovingPlanet()
{
}

void MovingPlanet::updateFrame(const QList<Planet *> &planets)
{
    qreal d, dx, dy, fg;
    qreal theta = 0;
    qreal G = 5.0;

    foreach (Planet *p, planets)
    {
        if (this == p || !inRangeOf(p) || intersects(p))
            continue;

        dx = p->centerX() - centerX();
        dy = p->centerY() - centerY();
        d = sqrt(dx*dx + dy*dy);

        theta = atan2(dy, dx);
        fg = G*((mass()*p->mass())/(d*d));
        _fgx += fg*cos(theta);
        _fgy += fg*sin(theta);
    }

    _fx += _fgx;
    _fy += _fgy;

    qreal ax = _fx/mass();
    qreal ay = _fy/mass();

    setVx(_vx + ax);
    setVy(_vy + ay);

    move(_vx, _vy);

    Planet::updateFrame(planets);

    _fx = 0;
    _fy = 0;
    _fgx = 0;
    _fgy = 0;
}

bool MovingPlanet::inRangeOf(Planet *p)
{
    qreal gLeft = p->centerX() - p->gravityRadius();
	qreal gRight = p->centerX() + p->gravityRadius();
	qreal gTop = p->centerY() - p->gravityRadius();
	qreal gBottom = p->centerY() + p->gravityRadius();

	if (left() > gRight)
		return false;
	if (gLeft > right())
		return false;
	if (top() > gBottom)
		return false;
	if (gTop > bottom())
		return false;

    qreal dx = p->centerX() - centerX();
    qreal dy = p->centerY() - centerY();
	qreal d = sqrt(dx*dx + dy*dy);

	return (d < radius() + p->gravityRadius());
}

void MovingPlanet::findCollisionPoint(Planet *p, qreal prevX, qreal prevY)
{
    qreal dx = prevX - this->centerX();
    qreal dy = prevY - this->centerY();
    qreal d = dx*dx + dy*dy;

    if (d < 1)
        return;

    qreal midX = 0.5*(prevX + this->centerX());
    qreal midY = 0.5*(prevY + this->centerY());

    Circle mid(midX, midY, this->radius());

    if (p->intersects(&mid))
    {
        this->setCenterX(midX);
        this->setCenterY(midY);
        findCollisionPoint(p, prevX, prevY);
    }
    else
    {
        findCollisionPoint(p, midX, midY);
    }
}

void MovingPlanet::collision(Planet *p)
{
    qreal prevX = x() - _vx;
    qreal prevY = y() - _vy;

    findCollisionPoint(p, prevX, prevY);

    qDebug() << endl << endl;

    _fx = 0;
    _fy = 0;
}

void MovingPlanet::move(qreal dx, qreal dy)
{
    moveX(dx);
    moveY(dy);
}

void MovingPlanet::moveX(qreal dx)
{
    setX(x() + dx);
}

void MovingPlanet::moveY(qreal dy)
{
    setY(y() + dy);
}



//****************************************SETTERS****************************************
void MovingPlanet::setVx(qreal vx)
{
    _vx = vx;
    emit vxChanged(); //for some reason gives an "undefined symbols for architectre" error
}

void MovingPlanet::setVy(qreal vy)
{
    _vy = vy;
    emit vyChanged();
}
//***************************************************************************************


//****************************************GETTERS****************************************
qreal MovingPlanet::vx() { return _vx; }
qreal MovingPlanet::vy() { return _vy; }
//***************************************************************************************
