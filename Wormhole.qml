import QtQuick 2.0
import wormhole 1.0

Wormhole
{
    id: main;

    planet1: Planet {
        parent: main.parent;
        radius: 10;
        baseColor: "black";
        color: baseColor
    }

    planet2: Planet {
        parent: main.parent;
        radius: 10;
        baseColor: "black";
        color: baseColor;
    }

    Rectangle
    {
        id: connectingLine;
        width: 1;
        color: "gray";
        transformOrigin: Item.Top;
        opacity: .5;
    }

    function calculateConnectingLine()
    {
        var dx = planet1.centerX - planet2.centerX;
        var dy = planet1.centerY - planet2.centerY;
        connectingLine.height = Math.sqrt(dx*dx + dy*dy);
        connectingLine.rotation = 90 + Math.atan2(dy, dx)*57.2957795; //radians to degrees
        connectingLine.x = planet1.centerX;
        connectingLine.y = planet1.centerY;
    }
}
