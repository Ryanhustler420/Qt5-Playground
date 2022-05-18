import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    id: root

    Rectangle {
        id: myShape
        color: "red"
        width: 100
        height: 100
        x: 0
        y: (parent.height / 2) - (height / 2)

        PropertyAnimation {
            id: animationRight
            target: myShape
            property: "x"
            to: root.width - myShape.width
            duration: 2000 // ms, effect the speed
        }

        PropertyAnimation {
            id: animationLeft
            target: myShape
            property: "x"
            to: 0
            duration: 500 // ms, effect the speed
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (myShape.x === 0) {
                    animationRight.start()
                    // animationRight.running = true;
                } else {
                    animationLeft.start()
                    // animationLeft.running = true;
                }
            }
        }

    }

}
