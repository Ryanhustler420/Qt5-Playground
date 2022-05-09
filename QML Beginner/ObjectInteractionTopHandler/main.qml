import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        height: 100
        width: 100
        anchors.centerIn: parent

        TapHandler {
            id: inputHandler
        }

        color: inputHandler.pressed ? "red" : "blue"
    }

}
