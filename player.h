#ifndef PLAYER_H
#define PLAYER_H

#include "movingplanet.h"
#include "target.h"

class Player : public MovingPlanet
{
		Q_OBJECT
	public:
		explicit Player(QQuickItem *parent = 0);
		~Player();

        void updateFrame(const QList<Planet*> &planets);

        void setMousePoint(const QPoint &p);
		void setMousePressed(bool b);

        QPoint mousePoint();
		bool mousePressed();

        Q_PROPERTY(QPoint mousePoint READ mousePoint WRITE setMousePoint NOTIFY mousePointChanged)
		Q_PROPERTY(bool mousePressed READ mousePressed WRITE setMousePressed NOTIFY mousePressedChanged)

	protected:
        QPoint _mousePoint;
		bool _mousePressed;

	signals:
        void mousePointChanged();
		void mousePressedChanged();
		void emitFuel(qreal xSpeed, qreal ySpeed);
        void hitTarget(Circle *target);
        void hitBonus(qreal bonusMass);
};

#endif // PLAYER_H
