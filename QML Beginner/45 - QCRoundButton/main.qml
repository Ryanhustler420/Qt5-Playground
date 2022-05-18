import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property real value: 0

    Row {
        id: row
        x: 0
        y: 0
        width: 239
        height: 43
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        RoundButton {
            id: roundButton
            text: "+"
            font.bold: true
            font.pointSize: 15
            onClicked: value++
        }

        RoundButton {
            id: roundButton1
            text: "-"
            font.bold: true
            font.pointSize: 15
            onClicked: value = Math.max(value - 1, 0)
        }

        Label {
            id: label
            text: "Value: " + window.value
            font.bold: true
            font.pointSize: 25
        }
    }
}
