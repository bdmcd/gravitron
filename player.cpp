#include "player.h"
#include "math.h"

Player::Player(QQuickItem *parent) : MovingPlanet(parent), _mousePressed(false)
{
}

Player::~Player()
{
}

void Player::updateFrame(const QList<Planet *> &planets)
{
	if(_mousePressed)
	{
        qreal dx = _mousePoint.x() - centerX();
        qreal dy = _mousePoint.y() - centerY();

		qreal theta = atan2(dy, dx);
        qreal ft = mass()*.07; //force of the thrust
        qreal ftx = ft*cos(theta);
        qreal fty = ft*sin(theta);

        _fx += ftx;
        _fy += fty;

//        this->setMass(mass()-.03);

        qreal fsf = 100/mass();  //fuel speed factor
        if (_frameCount%4 == 0)
            emit emitFuel(-ftx*fsf, -fty*fsf);
	}

	MovingPlanet::updateFrame(planets);
}

void Player::setMousePoint(const QPoint &p)
{
    _mousePoint = p;
    emit mousePointChanged();
}

void Player::setMousePressed(bool b)
{
	_mousePressed = b;
	emit mousePressedChanged();
}


QPoint Player::mousePoint() { return _mousePoint; }
bool Player::mousePressed() { return _mousePressed; }
