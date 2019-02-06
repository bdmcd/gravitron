#ifndef PLANET_H
#define PLANET_H

#include "circle.h"
#include <QDebug>

class Planet : public Circle
{
        Q_OBJECT
	public:
		explicit Planet(QQuickItem *parent = 0);
		~Planet();

		virtual void updateFrame(const QList<Planet*> &planets);
        virtual void collision(Planet *p);

		//****************************************SETTERS****************************************
        virtual void setMass(qreal m);
        virtual void setRadius(qreal r);
        virtual void setBaseColor(const QColor &c);
        virtual void setColor(const QColor &c);
		//***************************************************************************************

		//****************************************GETTERS****************************************
        qreal mass() const;
		qreal gravityRadius() const;
		QColor color() const;
        QColor baseColor() const;
		//***************************************************************************************

		//*************************************Q_PROPERTIES**************************************
		Q_PROPERTY(qreal mass READ mass WRITE setMass NOTIFY massChanged)
		Q_PROPERTY(qreal gravityRadius READ gravityRadius CONSTANT)
		Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
        Q_PROPERTY(QColor baseColor READ baseColor WRITE setBaseColor NOTIFY baseColorChanged)
		//***************************************************************************************

    protected:
        unsigned int _frameCount;

    private:
        qreal _mass;
        qreal _vx, _vy;
		QColor _color, _baseColor;

	signals:
		void massChanged();
		void colorChanged();
		void baseColorChanged();
        void gravityRadiusChanged();
        void frameUpdated();

	public slots:
};

#endif // PLANET_H
