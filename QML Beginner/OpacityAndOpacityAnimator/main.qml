import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    color: "black"

    Image {
        id: birthday
        source: "qrc:/images/IMG_5148.JPG"
        anchors.fill: parent
        opacity: 1
        fillMode: Image.PreserveAspectFit
    }

    SequentialAnimation {
        loops: Animation.Infinite
        running: true

        OpacityAnimator {
            target: birthday
            from: 0
            to: 1
            duration: 1000
        }

        OpacityAnimator {
            target: birthday
            from: 1
            to: 0
            duration: 5000
        }

    }

}
