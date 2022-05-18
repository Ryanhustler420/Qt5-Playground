import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string lockCode: "529"
    property string status: "Locked"

    Popup {
        id: popup
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        anchors.centerIn: parent
        width: 200
        height: 300
        focus: true
        modal: true
        Label {
            id: statusLabel
            anchors.centerIn: parent
            text: status
            font.bold: true
        }
    }

    Column {
        id: column
        x: 46
        y: 40
        width: 200
        height: 400
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: label
            text: qsTr("000")
            font.bold: true
            font.pointSize: 25
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            id: row
            width: 200
            height: 210

            Tumbler {
                id: tumbler
                anchors.left: parent.left
                anchors.leftMargin: 0
                model: 10
                onCurrentIndexChanged: label.text = `${tumbler.currentIndex} ${tumbler1.currentIndex} ${tumbler2.currentIndex}`
            }

            Tumbler {
                id: tumbler1
                anchors.left: tumbler.right
                anchors.right: tumbler2.left
                anchors.leftMargin: 10
                anchors.rightMargin: 10
                model: 10
                onCurrentIndexChanged: label.text = `${tumbler.currentIndex} ${tumbler1.currentIndex} ${tumbler2.currentIndex}`
            }

            Tumbler {
                id: tumbler2
                anchors.right: parent.right
                anchors.rightMargin: 0
                model: 10
                onCurrentIndexChanged: label.text = `${tumbler.currentIndex} ${tumbler1.currentIndex} ${tumbler2.currentIndex}`
            }
        }

        Button {
            id: button
            text: qsTr("Check")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                var tempCode = `${tumbler.currentIndex}${tumbler1.currentIndex}${tumbler2.currentIndex}`
                if (tempCode === lockCode) {
                    status = "Unlocked"
                }
                popup.open()
            }
        }
    }
}
