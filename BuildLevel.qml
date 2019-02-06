import QtQuick 2.4
import level 1.0

Level
{
    id: main;
    width: parent.width;
    height: parent.height;

    property MouseArea mouseArea: parent.mouseArea;

    target: Target {
        parent: main; //this needs to be here. Because goal is a property, the parent is not automatically assigned
        x: main.width/2 - width/2;
        y: 0;
        radius: 20;
    }

    player: Qt.createQmlObject("Player{mass:20}", main, 'Player');


    Planet
    {
        mass: 150;
        x: main.width/2 - radius;
        y: main.height/2 - height;

        Component.onCompleted: addPlanet(this);
    }
}
