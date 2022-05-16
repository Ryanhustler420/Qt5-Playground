import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        id: row
        x: 6
        y: 14
        width: 232
        height: 40
        anchors.verticalCenter: parent.verticalCenter
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter

        DelayButton {
            id: delayButton
            text: qsTr("Delete Everything")
            delay: 300
            onProgressChanged: {
                label.text = Math.round(progress * 100)
                if (progress === 0) {
                    text = "Delete Everything"
                    label.text = "Status"
                }
            }
            onActivated: {
                label.text = "Status"
                text = "BOOOM"
            }
        }

        Label {
            id: label
            text: qsTr("Status")
            font.bold: true
            font.pointSize: 25
        }
    }
}


