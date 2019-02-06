#ifndef MOVINGPLANET_H
#define MOVINGPLANET_H

#include "planet.h"

class MovingPlanet : public Planet
{
		Q_OBJECT
	public:
		explicit
		MovingPlanet(QQuickItem *parent = 0);
		~MovingPlanet();

		virtual void updateFrame(const QList<Planet *> &planets);
		bool inRangeOf(Planet *p);
        void collision(Planet *p);

        void move(qreal dx, qreal dy);
        void moveX(qreal dx);
        void moveY(qreal dy);

		//****************************************SETTERS****************************************
        void setVx(qreal vx);
        void setVy(qreal vy);
		//***************************************************************************************


		//****************************************GETTERS****************************************
        qreal vx();
        qreal vy();
		//***************************************************************************************


		//*************************************Q_PROPERTIES**************************************
        Q_PROPERTY(qreal vx READ vx WRITE setVx NOTIFY vxChanged)
        Q_PROPERTY(qreal vy READ vy WRITE setVy NOTIFY vyChanged)
		//***************************************************************************************

	protected:
        qreal _vx, _vy, _fx, _fy, _fgx, _fgy;
        void findCollisionPoint(Planet *p, qreal prevX, qreal prevY);

	signals:
        void vxChanged();
        void vyChanged();

	public slots:

};

#endif // MOVINGPLANET_H
