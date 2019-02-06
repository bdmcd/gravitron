#ifndef BONUS_H
#define BONUS_H

#include "circle.h"

class Bonus : public Circle
{
    Q_OBJECT
public:
    explicit Bonus(QQuickItem *parent = 0);
    ~Bonus();

    qreal mass();
    void setMass(qreal m);

    Q_PROPERTY(qreal mass READ mass WRITE setMass NOTIFY massChanged)

private:
    qreal _mass;

signals:
    void massChanged();
    void hit();

public slots:
};

#endif // BONUS_H
