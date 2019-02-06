import QtQuick 2.4
import target 1.0

Target
{
    id: main;

    width: radius*2;
    height: width;

    Rectangle
    {
        anchors.fill: parent;
        radius: width;
        border.width: width/10;
        border.color: "black"
    }
}
