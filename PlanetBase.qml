import QtQuick 2.4
import QtGraphicalEffects 1.0

Item
{
	id: main;
	anchors.fill: parent;
	property color color: parent.color;
	property alias planetCircle: planetItem;
    property alias gravityCircle: gravityItem;

    RadialGradient
    {
        id: gravityItem;
        anchors.centerIn: parent;
        property double radius;
        width: radius*2;
        height: radius*2;
        opacity: .2

        gradient: Gradient {
            GradientStop { position: ((planetItem.width/2)/gravityItem.radius)/2; color: main.color; }
            GradientStop { position: 0.5; color: "transparent"; }
        }
    }

	Rectangle
	{
		radius: width;
		id: planetItem;
		color: main.color;
		anchors.fill: parent;
	}
}

