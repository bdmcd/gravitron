#include "compass.h"
#include "globals.h"
#include <math.h>

Compass::Compass(QQuickItem *parent) : QQuickItem(parent)
{
    this->setVisible(true);
}

Compass::~Compass()
{
}

void Compass::updateFrame(Player *player, Target *target)
{
    if (!player || !target)
        return;

    qreal dx = target->centerX() - player->centerX();
    qreal dy = target->centerY() - player->centerY();
    qreal theta = (atan2(dy, dx)*57.2957795);

    this->setRotation(theta);
}
