#ifndef COMPASS_H
#define COMPASS_H

#include <QQuickItem>
#include "player.h"
#include "target.h"

class Compass : public QQuickItem
{
    Q_OBJECT
public:
    explicit Compass(QQuickItem *parent = 0);
    ~Compass();

    void updateFrame(Player *player, Target *target);

signals:

public slots:
};

#endif // COMPASS_H
