import QtQuick 2.4
import planet 1.0

Planet
{
	id: main;
	baseColor: "steelblue";

	PlanetBase
	{
		id: planetBase;
	}

    onGravityRadiusChanged: planetBase.gravityCircle.radius = gravityRadius;
}
