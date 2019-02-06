#include "planet.h"
#include "math.h"

Planet::Planet(QQuickItem *parent) : Circle(parent), _frameCount(0)
{
}

Planet::~Planet()
{
}


void Planet::updateFrame(const QList<Planet *> &planets)
{
    foreach (Planet *p, planets)
    {
        if (this == p)
            continue;

        if(this->intersects(p))
            collision(p);
    }

    emit frameUpdated();
	_frameCount++;
}

void Planet::collision(Planet *p)
{
//	if (this->mass() > p->mass())
//	{
//        qreal dm = .5;
//		this->setMass(mass()+dm);
//		p->setMass(p->mass()-dm);
//	}
}

//****************************************SETTERS****************************************
void Planet::setMass(qreal m)
{
	_mass = m;

	qreal factor = _mass/7 + 65;
	if (factor > 270)
		factor = 270;
	setColor(_baseColor.darker(factor));

    setRadius(sqrt(_mass)*4);

    emit massChanged();
}

void Planet::setRadius(qreal r)
{
    Circle::setRadius(r);
    emit gravityRadiusChanged();
}

void Planet::setBaseColor(const QColor &c)
{
	_baseColor = c;
	emit baseColorChanged();
}

void Planet::setColor(const QColor &c)
{
	_color = c;
	emit colorChanged();
}

//**************************************************************************************


//****************************************GETTERS***************************************
qreal Planet::mass() const { return _mass; }
qreal Planet::gravityRadius() const { return radius() + _mass*1.75; }
QColor Planet::color() const { return _color; }
QColor Planet::baseColor() const { return _baseColor; }
//**************************************************************************************
