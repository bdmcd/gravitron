#include "level.h"

Level::Level(QQuickItem *parent) : QQuickItem(parent), _target(NULL), _player(NULL)
{
}

Level::~Level()
{
    foreach (Planet *p, _planets)
    {
        removePlanet(p);
    }
    foreach (Bonus *b, _bonuses)
    {
        removeBonus(b);
        delete b;
    }
    foreach (Wormhole *w, _wormholes)
    {
        removeWormhole(w);
    }

    delete _target;
}

void Level::updateFrame()
{
    foreach(Bonus *b, _bonuses)
    {
        if (_player->intersects(b))
        {
            emit _player->hitBonus(b->mass());
            emit b->hit();
            removeBonus(b);
        }
    }

    foreach(Planet *p, _planets)
    {
        p->updateFrame(_planets);

        if (p->radius() < 1)
            removePlanet(p);
    }

    foreach(Wormhole *w, _wormholes)
    {
        w->updateFrame(_player);
    }
}

void Level::addPlanet(Planet *p)
{
    _planets.append(p);
}
void Level::removePlanet(Planet *p)
{
    _planets.removeAll(p);
    delete p;
}

void Level::addBonus(Bonus *b)
{
    _bonuses.append(b);
}
void Level::removeBonus(Bonus *b)
{
    _bonuses.removeAll(b);
}

void Level::addWormhole(Wormhole *w)
{
    _wormholes.append(w);
}
void Level::removeWormhole(Wormhole *w)
{
    _wormholes.removeAll(w);
    delete w;
}

//***************************SETTERS***************************
void Level::setTarget(Target *t)
{
    if (_target)
        delete _target;

    _target = t;
    emit targetChanged();
}

void Level::setPlayer(Player *p)
{
    if (_player)
        removePlanet(_player);

    _player = p;
    this->addPlanet(_player);
    emit playerChanged();
}
//*************************************************************

//***************************GETTERS***************************
QList<Planet*> Level::planets() { return _planets; }
Planet* Level::planetAt(int index) { return _planets[index]; }
int Level::numPlanets() { return _planets.size(); }
Target* Level::target() { return _target; }
Player* Level::player() { return _player; }
//*************************************************************
