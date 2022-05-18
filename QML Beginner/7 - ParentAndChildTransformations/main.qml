import QtQuick 2.12
import QtQuick.Window 2.12

// Parent and children relationships

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image {
        id: name
        source: "file:///E:/SukriBirthday/IMG_5060.JPG"
        width: 150
        height: 100
        x: 100
        y: 100
        z: 3

        Rectangle {
            color: "red"
            x: -25
            y: -25
            width: 50
            height: 50
            opacity: .5
            z: 1
        }

        Rectangle {
            color: "blue"
            x: parent.width - width
            y: parent.height - height
            width: 50
            height: 50
            opacity: .5
            z: 0
        }
    }

}
