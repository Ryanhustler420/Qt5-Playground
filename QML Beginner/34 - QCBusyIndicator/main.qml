import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    BusyIndicator {
        id: busyIndicator
        running: true
        x: 290
        y: 210
    }

    Label {
        id: label
        x: 299
        y: 191
        text: qsTr("Please wait")

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (busyIndicator.running) {
                    busyIndicator.running = false
                    label.text = qsTr("One last moment before you take you on the other side")
                } else {
                    busyIndicator.running = true
                    label.text = qsTr("Please wait")
                }
            }
        }

    }

}
