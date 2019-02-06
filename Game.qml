import QtQuick 2.4
import game 1.0

Game
{
    id: game;
    anchors.fill: parent;

    level: Level {
        parent: game;
        levelNumber: 4;
    }

    compass: Compass {
        parent: game;
    }

    Timer
    {
        id: timer;
        interval: 1000/60;
        running: true;
        repeat: true;

        onTriggered: {
            game.updateFrame();
        }
    }

    onStopTimer: timer.stop();
    onStartTimer: timer.start();
}

