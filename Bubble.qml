import QtQuick 2.4
import movingPlanet 1.0

Rectangle
{
	id: main;
	color: parent.color;

    width: Math.sqrt(parent.mass)*2;
	height: width;
	z: parent.z - 1;
	radius: width;

	x: (parent.width/2) - (width/2);  //relative to the player
	y: (parent.height/2) - (height/2);

	property double vx;
	property double vy;

	Timer
	{
		running: true;
		repeat: true;
		interval: 1000/60;

		onTriggered:
		{
			x += vx;
			y += vy;
			opacity -= .05;
			if (opacity <= 0)
				main.destroy();
		}
	}
}

