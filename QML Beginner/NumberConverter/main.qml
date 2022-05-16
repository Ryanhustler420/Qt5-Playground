import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function convert() {
        var value = txtFrom.text
        var ret = 0

        switch(cmbType.currentIndex) {
        case 0: // inches to feet
            ret = inch_to_feet(value)
            break
        case 1: // feet to inches
            ret = feet_to_inchs(value)
            break;
        }

        lblResult.text = ret

    }

    function inch_to_feet(value) {
        return value / 12
    }

    function feet_to_inchs(value) {
        return value * 12
    }

    Column {
        id: column
        width: 372
        height: 214
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        Grid {
            id: grid
            width: 400
            height: 230
            clip: false
            spacing: 10
            columns: 2

            Label {
                id: label
                text: qsTr("Type:")
            }

            ComboBox {
                id: cmbType
                model: ListModel {
                    id: cbItems
                    ListElement {
                        text: "Inches to feet"
                    }
                    ListElement {
                        text: "Feet to inches"
                    }
                }
            }

            Label {
                id: label1
                text: qsTr("From:")
            }

            TextField {
                id: txtFrom
            }

            Label {
                id: label2
                text: qsTr("Result:")
            }

            Label {
                id: lblResult
                text: qsTr("Nothing")
                font.pointSize: 15
                font.bold: true
            }
        }

        Button {
            id: button
            text: qsTr("Convert")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: convert()
        }
    }
}
