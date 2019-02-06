import QtQuick 2.4
import player 1.0

Player
{
    id: player;
	baseColor: "green";

    property double scaleSqrt: Math.sqrt(parent.scale);
    property double xDiff: (parent.parent.x - parent.x)/scaleSqrt;
    property double yDiff: (parent.parent.y - parent.y)/scaleSqrt;

    mousePressed: mouseArea.pressed;
    mousePoint.x: mouseArea.mouseX - (mouseArea.width-parent.width)/2 + xDiff;
    mousePoint.y: mouseArea.mouseY - (mouseArea.height-parent.height)/2 + yDiff;

    property MouseArea mouseArea;

    PlanetBase
    {
        id: planetBase;
    }

    property int animDur: 0;
    Component.onCompleted:
    {
        centerX = parent.width/2;
        centerY = parent.height*.8;
    }

    onFrameUpdated:
    {
        var yDiff = (parent.parent.y - parent.y);
        var xDiff = (parent.parent.x - parent.x);

        if (vy < 0 && centerY < parent.height*.2 + yDiff)
            parent.y -= vy;
        else if (vy > 0 && centerY > parent.height*.8 + yDiff)
            parent.y -= vy;

        if (vx < 0 && centerX < parent.width*.2 + xDiff)
            parent.x -= vx;
        else if (vx > 0 && centerX > parent.width*.8 + xDiff)
            parent.x -= vx;
    }

    onEmitFuel:
    {
        var bubble = Qt.createQmlObject("Bubble{}", this, 'Bubble');
        bubble.vx = xSpeed;
        bubble.vy = ySpeed;
    }

    Behavior on x{ PropertyAnimation{ duration: animDur; } }
    Behavior on y{ PropertyAnimation{ duration: animDur; } }
    Behavior on width{ PropertyAnimation{ duration: animDur; } }
    Behavior on height{ PropertyAnimation{ duration: animDur; } }
    Behavior on mass { PropertyAnimation{ duration: 200; } }

    onHitTarget:
    {
        animDur = 200;
        var newRadius = target.radius*.9;
        width = newRadius*2;
        height = newRadius*2
        x = target.centerX - newRadius;
        y = target.centerY - newRadius;
        animDur = 0;
    }

    onHitBonus:
    {
        mass += bonusMass;
    }
}
