import QtQuick 2.4
import QtQuick.Window 2.0

Window
{
    id: main;
    visible: true
    width: 600;
    height: 800;

    Game
    {
        id: game;
    }

    onWidthChanged: setSize();
    onHeightChanged: setSize();
    Component.onCompleted: {
        setSize();
        Globals.setRootItem(game);
    }

    function setSize()
    {
        Globals.setScreenSize(Qt.size(main.width, main.height))
    }
}
