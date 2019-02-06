import QtQuick 2.4
import level 1.0
import levelLoader 1.0

Level
{
    id: level;
    anchors.fill: parent;
    onWidthChanged: console.log("WIDTH:", width);
    onHeightChanged: console.log("HEIGHT", height);
    Component.onCompleted: init();

    property MouseArea mouseArea;
    property int levelNumber: 1;

    function init() {
        if (width > 0 && height > 0) {
            loader.loadLevel(levelNumber);
        } else {
            level.heightChanged.connect(init);
            level.widthChanged.connect(init);
        }
    }

    MouseArea
    {
        id: mouse;
        scale: level.scale;
        parent: level.parent;
        anchors.centerIn: parent;
        width: parent.width/scale;
        height: parent.height/scale;
    }

    LevelLoader
    {
        id: loader;

        onPlayerLoaded:
        {
            level.player = Qt.createQmlObject("Player{ mouseArea: mouse; }", level, 'Player');
            level.player.mass = playerMass;
            level.player.z = level.z + 100;
        }

        onTargetLoaded:
        {
            level.target = Qt.createQmlObject("Target{}", level, 'Target');
            level.target.radius = targetRadius;
            level.target.centerX = targetX;
            level.target.centerY = targetY;
        }

        onPlanetLoaded:
        {
            var planet = Qt.createQmlObject("Planet{}", level, 'Planet');
            planet.mass = planetMass;
            planet.centerX = planetX;
            planet.centerY = planetY;
            level.addPlanet(planet);
        }

        onMovingPlanetLoaded:
        {
            var planet = Qt.createQmlObject("MovingPlanet{}", level, 'MovingPlanet');
            planet.mass = planetMass;
            planet.centerX = planetX;
            planet.centerY = planetY;
            planet.vx = planetVX;
            planet.vy = planetVY;
            level.addPlanet(planet);
        }

        onBonusAdded:
        {
            var bonus = Qt.createQmlObject("Bonus{}", level, 'Bonus');
            bonus.mass = bonusMass;
            bonus.centerX = bonusX;
            bonus.centerY = bonusY;
            level.addBonus(bonus);
        }

        onWormholeAdded:
        {
            var wormhole = Qt.createQmlObject("Wormhole{}", level, 'Wormhole');
            wormhole.planet1.x = wormholeX1;
            wormhole.planet1.y = wormholeY1;
            wormhole.planet2.x = wormholeX2;
            wormhole.planet2.y = wormholeY2;
            wormhole.angle1 = wormholeAngle1/57.2957795; //degrees to radians
            wormhole.angle2 = wormholeAngle2/57.2957795;
            wormhole.calculateConnectingLine();
            level.addWormhole(wormhole);
        }
    }
}
