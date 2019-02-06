#include "bonus.h"
#include "math.h"

Bonus::Bonus(QQuickItem *parent) : Circle(parent)
{
}

Bonus::~Bonus()
{
}

void Bonus::setMass(qreal m)
{
    _mass = m;
    setRadius(sqrt(_mass)*4);
    emit massChanged();
}

qreal Bonus::mass() { return _mass; }
