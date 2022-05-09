import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        color: "black"
        focus: true

        Rectangle {
            width: 60
            height: 60
            color: "yellow"
            radius: width

            // Property binding
            x: rect1.x - 5
            y: rect1.y - 5

            Behavior on x {
                SmoothedAnimation {
                    velocity: 100 // 50, 60, n
                }
            }

            Behavior on y {
                SmoothedAnimation {
                    velocity: 100
                }
            }

        }

        Rectangle {
            id: rect1
            width: 50
            height: 50
            color: "red"
            radius: width
            x: (parent.width / 2) - (width / 2)
            y: (parent.height / 2) - (height / 2)
        }

        Keys.onRightPressed: rect1.x += 100
        Keys.onLeftPressed: rect1.x -= 100
        Keys.onUpPressed: rect1.y -= 100
        Keys.onDownPressed: rect1.y += 100

    }

}
