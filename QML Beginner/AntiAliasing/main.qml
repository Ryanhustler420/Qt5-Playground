import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    Row {
        anchors.centerIn: parent
        spacing: 20

        Rectangle {
            width: 200
            height: 200
            border.color: "red"
            border.width: 20
            radius: width

            Text {
                anchors.centerIn: parent
                text: qsTr("Turned On")
            }
        }

        Rectangle {
            width: 200
            height: 200
            border.color: "red"
            border.width: 20
            radius: width
            antialiasing: false // this will make rough edged, else bydefault it's turn on always

            Text {
                anchors.centerIn: parent
                text: qsTr("Turned Off")
            }
        }

    }

}
