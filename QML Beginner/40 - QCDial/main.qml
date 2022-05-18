import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        x: 142
        y: 40
        width: 278
        height: 308
        anchors.verticalCenter: parent.verticalCenter
        spacing: 50
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: label
            text: qsTr("Value")
            font.pointSize: 40
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Dial {
            id: dial
            anchors.horizontalCenter: parent.horizontalCenter
            onMoved: {
                label.text = Math.round(dial.value * 100)
            }
        }
    }
}
