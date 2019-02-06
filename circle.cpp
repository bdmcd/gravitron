#include "circle.h"
#include "globals.h"
#include <math.h>

Circle::Circle(QQuickItem *parent) : QQuickItem(parent), _radius(0)
{
}

Circle::Circle(qreal centerX, qreal centerY, qreal radius)
{
    setRadius(radius);
    setCenterX(centerX);
    setCenterY(centerY);
}

Circle::~Circle()
{
}

bool Circle::intersects(Circle *c)
{
    if (left() > c->right())
        return false;
    if (c->left() > right())
        return false;
    if(top() > c->bottom())
        return false;
    if (c->top() > bottom())
        return false;

    qreal dx = c->centerX() - centerX();
    qreal dy = c->centerY() - centerY();
    qreal dSquared = dx*dx + dy*dy;
    qreal r = radius() + c->radius();
    qreal rSquared = r*r;

    return (dSquared < rSquared);
}

bool Circle::isOnScreen()
{
    QPointF globalPosition = this->mapToItem(Globals::rootItem(), QPoint(0, 0));

    if (globalPosition.x() < 0)
        return false;
    if (globalPosition.x() + width() > Globals::screenSize().width())
        return false;
    if (globalPosition.y() < 0)
        return false;
    if (globalPosition.y() + height() > Globals::screenSize().height())
        return false;

    return true;
}

QPointF Circle::globalCenter()
{
    return this->mapToItem(Globals::rootItem(), QPoint(radius(), radius()));
}

void Circle::setRadius(qreal r)
{
    qreal diff = r - _radius;
    _radius = r;
    this->setWidth(r*2);
    this->setHeight(r*2);
    this->setX(x() - diff);
    this->setY(y() - diff);
    emit radiusChanged();
}

void Circle::setCenterX(qreal centerX)
{
    setX(centerX - radius());
    emit centerXChanged();
}

void Circle::setCenterY(qreal centerY)
{
    setY(centerY - radius());
    emit centerYChanged();
}

qreal Circle::left() const { return x(); }
qreal Circle::right() const { return x() + width(); }
qreal Circle::top() const { return y(); }
qreal Circle::bottom() const { return y() + height(); }
qreal Circle::centerX() const { return x() + radius(); }
qreal Circle::centerY() const { return y() + radius(); }
qreal Circle::radius() const { return _radius; }
