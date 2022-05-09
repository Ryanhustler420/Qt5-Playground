import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        // @disable-check M31
        // @disable-check M16

        id: myShape
        width: 100
        height: 100
        color: "orange"

        // it has access to all of Rectangle properties
        function update() {
            console.log(x, "x", y)
            label.text = Math.round(x) + " x " + Math.round(y)
        }

        // anchors.centerIn: parent // anchors win over x, y positioning
        x: 100
        y: 100

        onXChanged: update()
        onYChanged: update()

        Component.onCompleted: update()

        Text {
            id: label
            text: qsTr("text")
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            drag.target: parent
        }

    }

}
