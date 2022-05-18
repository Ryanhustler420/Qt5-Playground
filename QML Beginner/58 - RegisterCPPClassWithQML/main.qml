import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

// Import out class/type
import software.raisehand.test 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Test {
        id: test
        onStatus: {
            lblStatus.text = data // data is QVariant with same name
        }
    }

    Column {
        id: column
        width: 101
        height: 88
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10

        Label {
            id: label
            text: qsTr("Register a c++ class")
            font.bold: false
            font.pointSize: 10
        }

        Label {
            id: lblStatus
            text: qsTr("Status")
            anchors.horizontalCenter: parent.horizontalCenter
            font.bold: true
            font.pointSize: 25
        }

        Button {
            id: button
            text: qsTr("Click Me")
            onClicked: {
                // anything...
                var num = Math.round(Math.random() * 100)
                test.work(num)
            }
        }

    }

}
