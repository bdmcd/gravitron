import QtQuick 2.4
import movingPlanet 1.0

MovingPlanet
{
	id: main;
	baseColor: "firebrick";

	PlanetBase
	{
		id: planetBase
	}

    onGravityRadiusChanged: planetBase.gravityCircle.radius = gravityRadius;
}
