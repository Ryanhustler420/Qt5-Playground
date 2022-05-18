import QtQuick 2.12
import QtQuick.Window 2.12

// Its an Item
// There is no circle!

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: myItem
        anchors.centerIn: parent
        color: "red"
        width: 200
        height: 200
        visible: true // bydefault

        border.color: "#000000" // or "blue"
        border.width: 5 // pixels

        radius: width // or 100
        gradient: Gradient {
            GradientStop { position: 0.0; color: "red" }
            GradientStop { position: 1.0; color: "blue" }
        }

    }

}
