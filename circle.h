#ifndef CIRCLE_H
#define CIRCLE_H

#include <QQuickItem>
#include <QPointF>

class Circle : public QQuickItem
{
    Q_OBJECT
public:
    Circle(QQuickItem *parent = 0);
    Circle(qreal centerX, qreal centerY, qreal radius);
    ~Circle();

    bool intersects(Circle *c);
    bool isOnScreen();

    QPointF globalCenter();

    qreal left() const;
    qreal right() const;
    qreal top() const;
    qreal bottom() const;
    qreal centerX() const;
    qreal centerY() const;
    qreal radius() const;

    virtual void setRadius(qreal r);
    void setCenterX(qreal centerX);
    void setCenterY(qreal centerY);

    Q_PROPERTY(qreal centerX READ centerX WRITE setCenterX NOTIFY centerXChanged)
    Q_PROPERTY(qreal centerY READ centerY WRITE setCenterY NOTIFY centerYChanged)
    Q_PROPERTY(QPointF globalCenter READ globalCenter CONSTANT)
    Q_PROPERTY(qreal left READ left CONSTANT)
    Q_PROPERTY(qreal right READ right CONSTANT)
    Q_PROPERTY(qreal top READ top CONSTANT)
    Q_PROPERTY(qreal bottom READ bottom CONSTANT)
    Q_PROPERTY(qreal radius READ radius WRITE setRadius NOTIFY radiusChanged)

private:
    qreal _radius;

signals:
    void radiusChanged();
    void centerXChanged();
    void centerYChanged();

public slots:
};

#endif // CIRCLE_H
