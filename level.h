#ifndef LEVEL_H
#define LEVEL_H

#include <QQuickItem>
#include "player.h"
#include "target.h"
#include "bonus.h"
#include "wormhole.h"

class Level : public QQuickItem
{
    Q_OBJECT
public:
    explicit Level(QQuickItem *parent = 0);
    ~Level();

    void updateFrame();

    Q_INVOKABLE void addPlanet(Planet *p);
    Q_INVOKABLE void removePlanet (Planet *p);
    Q_INVOKABLE void addBonus(Bonus *b);
    Q_INVOKABLE void removeBonus(Bonus *b);
    Q_INVOKABLE void addWormhole(Wormhole *w);
    Q_INVOKABLE void removeWormhole(Wormhole *w);

    //***************************SETTERS***************************
    void setTarget(Target *t);
    void setPlayer(Player *p);
    //*************************************************************

    //***************************GETTERS***************************
    QList<Planet*> planets();
    Planet* planetAt(int index);
    int numPlanets();
    Target* target();
    Player* player();
    //*************************************************************

    //************************Q_PROPERTIES*************************
    Q_PROPERTY(int numPlanets READ numPlanets CONSTANT)
    Q_PROPERTY(Target* target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(Player* player READ player WRITE setPlayer NOTIFY playerChanged)
    //*************************************************************

private:
    Target *_target;
    Player *_player;
    QList<Planet*> _planets;
    QList<Bonus*> _bonuses;
    QList<Wormhole*> _wormholes;

signals:
    void targetChanged();
    void playerChanged();

public slots:
};

#endif // LEVEL_H
