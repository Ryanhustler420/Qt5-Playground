import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: myShape
        color: "red"
        height: 200
        width: 200
        anchors.centerIn: parent

        Text {
            id: title
            text: Math.round(parent.rotation) // 12.35644
            anchors.centerIn: parent
            font.bold: true
            font.pointSize: 65
            color: "white"
        }

        RotationAnimation {
            id: animation
            target: myShape
            loops: Animation.Infinite // or 2, 45, 65, any number of times
            from: myShape.rotation
            to: 360 // -360 BAD
            direction: RotationAnimation.Clockwise // RotationAnimation.Counterclockwise
            duration: 3000 // 3s
            running: true
        }

        MouseArea {
            id: area
            anchors.fill: parent
            onClicked: {
                if (animation.paused) {
                    animation.resume()
                } else {
                    animation.pause()
                }
            }
        }

    }

}
