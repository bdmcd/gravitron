#include "game.h"
#include "levelloader.h"

Game::Game(QQuickItem *parent) : QQuickItem(parent), _level(NULL), _compass(NULL)
{
}

Game::~Game()
{
}

void Game::updateFrame()
{
    if (!_level || _level->player() == NULL || _level->target() == NULL)
        return;

    if (_level->player()->radius() < 1)
        stopTimer();

    if (_level->player()->intersects(_level->target()))
    {
        emit _level->player()->hitTarget(_level->target());
        stopTimer();
    }

    _compass->updateFrame(_level->player(), _level->target());

    _level->updateFrame();
}

//****************************************SETTERS****************************************
void Game::setLevel(Level *l)
{
    _level = l;
    emit levelChanged();
}

void Game::setCompass(Compass *c)
{
    _compass = c;
    emit compassChanged();
}
//***************************************************************************************


//****************************************GETTERS****************************************
Level* Game::level() { return _level; }
Compass* Game::compass() { return _compass; }
//***************************************************************************************
