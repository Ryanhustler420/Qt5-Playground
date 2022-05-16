import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    color: "#686060"
    title: qsTr("Hello World")

    Row {
        id: row
        height: 45
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.rightMargin: 1
        anchors.leftMargin: 1

        Button {
            id: button
            x: 2
            y: 0
            text: qsTr("First Image")
            leftPadding: 0
            wheelEnabled: true
            highlighted: true
            onClicked: {
                image1.source = "qrc:/images/images/IMG_5085.JPG";
            }
        }

        Button {
            id: button1
            x: 102
            y: 0
            text: qsTr("Second Image")
            leftPadding: 0
            wheelEnabled: true
            flat: false
            highlighted: true
            onClicked: {
                image1.source = "qrc:/images/images/IMG_5078.JPG";
            }
        }

        Button {
            id: button2
            x: 202
            y: 0
            text: qsTr("Third Image")
            leftPadding: 0
            wheelEnabled: true
            highlighted: true
            onClicked: {
                image1.source = "qrc:/images/images/IMG_5076.JPG";
            }
        }

        Button {
            id: button3
            x: 302
            y: 0
            text: qsTr("Fourth Image")
            leftPadding: 0
            wheelEnabled: true
            highlighted: true
            onClicked: {
                image1.source = "qrc:/images/images/IMG_5075.JPG";
            }
        }
    }

    Image {
        id: image1
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 75
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        fillMode: Image.PreserveAspectFit
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}D{i:6}
}
##^##*/
