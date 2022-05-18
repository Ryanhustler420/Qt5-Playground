import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        anchors.centerIn: parent
        width: 300
        height: 400
        color: "red"

        Rectangle {
            height: 100
            width: 100
            color: "yellow"

            // No anchors bydefault
            anchors.margins: 50 // All margins

            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.leftMargin: 15

            // If no anchors set then margin won't work at all
        }

    }

}
