import QtQuick 2.0
import bonus 1.0

Bonus
{
    id: main;

    Rectangle
    {
        anchors.fill: parent;
        radius: width;
        color: "gold";
    }

    Behavior on radius { PropertyAnimation { duration: 200; } }

    onHit:
    {
        radius = 0;
    }
}

