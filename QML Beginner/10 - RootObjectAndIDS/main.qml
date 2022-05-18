import QtQuick 2.12
import QtQuick.Window 2.12

// ID - must be unique
// Root Object - there can be only one root object

// Top Level object is the root object
Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image {
        // id: root // not possible same id
        id: myImage
        source: "file:///E:/SukriBirthday/IMG_5057.JPG"
        width: 150
        height: 100
        anchors.centerIn: parent

        Rectangle {
            color: "black"
            width: parent.width
            height: parent.height
            // height: 50
            opacity: .5 // 50% - .0 - 1.0
        }

    }

}
