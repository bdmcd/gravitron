import QtQuick 2.0
import compass 1.0

Compass
{
    id: main;
    width: parent.width/50;
    height: width;
    x: width/2;
    y: x;

    Image
    {
        anchors.fill: parent;
        sourceSize: Qt.size(width, height);
        asynchronous: true;
        source: "qrc:/pointer.png";
        rotation: 90;
    }
}
