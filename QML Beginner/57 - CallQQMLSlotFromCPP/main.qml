import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

// This is the root context

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Connections {
        target: test // our c++ object on the root context
        onNotice: {
            console.log("Slot called froom c++")
            lblStatus.text = data // get this from the signal, the name should be same as arg of signal
        }
    }

    Column {
        id: column
        width: 228
        height: 159
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 25

        Label {
            id: lblTitle
            text: "Connecting to Signal"
            font.pointSize: 10
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Label {
            id: lblStatus
            text: "Status"
            font.pointSize: 25
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            id: row
            width: parent.width
            spacing: 25

            Button {
                id: startBtn
                text: "Start"
                // call a slot
                onClicked: {
                    test.start();
                }
            }

            Button {
                id: stopBtn
                text: "Stop"
                // call a slot
                onClicked: {
                    test.stop();
                }
            }

        }

    }

}
