import QtQuick 2.12
import QtQuick.Window 2.12

// X Y Z - 3D

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image {
        id: image
        source: "file:///E:/SukriBirthday/IMG_5060.JPG"
        width: 150
        height: 100
        x: 100 // in pixels
        y: 100 // in pixels
        z: 4
    }

    Rectangle {
        color: "red"
        width: 200
        height: 200
        x: 50
        y: 50
        opacity: .5
        z: 2
    }

    Rectangle {
        color: "blue"
        width: 200
        height: 200
        x: 150
        y: 150
        opacity: .5
        z: 0
    }
}
