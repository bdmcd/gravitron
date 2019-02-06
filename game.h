#ifndef GAME_H
#define GAME_H

#include <QQuickItem>
#include "level.h"
#include "compass.h"

class Game : public QQuickItem
{
    Q_OBJECT
public:
    explicit Game(QQuickItem *parent = 0);
    ~Game();

    Q_INVOKABLE void updateFrame();


    //****************************************SETTERS****************************************
    void setLevel(Level *l);
    void setCompass(Compass *c);
    //***************************************************************************************

    //****************************************GETTERS****************************************
    Level* level();
    Compass* compass();
    //***************************************************************************************

    //*************************************Q_PROPERTIES**************************************
    Q_PROPERTY(Level* level READ level WRITE setLevel NOTIFY levelChanged)
    Q_PROPERTY(Compass* compass READ compass WRITE setCompass NOTIFY compassChanged)
    //***************************************************************************************

private:
    Level *_level;
    Compass *_compass;

signals:
    void levelChanged();
    void compassChanged();
    void stopTimer();
    void startTimer();
    void restartTimer();

public slots:
};

#endif // GAME_H
