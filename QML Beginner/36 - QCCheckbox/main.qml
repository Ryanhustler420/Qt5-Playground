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
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.rightMargin: 0




        Column {
            id: column
            width: 150
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            spacing: 10
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 0

            CheckBox {
                id: checkBox
                text: qsTr("Normal")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 0
                anchors.rightMargin: 0
                antialiasing: false
            }

            CheckBox {
                id: checkBox1
                text: qsTr("Not Checkale")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                checkable: false
            }

            CheckBox {
                id: checkBox2
                text: qsTr("Tristate")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                tristate: true
            }

            CheckBox {
                id: checkBox3
                text: qsTr("Exclusive")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                autoExclusive: true
            }

            CheckBox {
                id: checkBox4
                text: qsTr("Repeat")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.rightMargin: 0
                anchors.leftMargin: 0
                autoRepeat: true
            }

            Button {
                id: button
                text: qsTr("Reset")
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: 0
                anchors.rightMargin: 0
            }
        }

        Column {
            id: column1
            x: 150
            width: parent.width - x
            height: parent.height - y
            layer.format: ShaderEffectSource.RGBA

            Label {
                id: label
                text: qsTr("Status here")
                anchors.verticalCenter: parent.verticalCenter
                antialiasing: true
                font.bold: true
                font.pointSize: 35
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    Connections {
        target: button
        onClicked: {
            checkBox.checkState = Qt.Unchecked
            checkBox1.checkState = Qt.Unchecked
            checkBox2.checkState = Qt.Unchecked
            checkBox3.checkState = Qt.Unchecked
            checkBox4.checkState = Qt.Unchecked
        }
    }

    Connections {
        target: checkBox
        onClicked: {
            label.text = "checkbox = " + target.checkState
        }
    }

    Connections {
        target: checkBox1
        onClicked: {
            label.text = "checkbox = " + target.checkState
        }
    }

    Connections {
        target: checkBox2
        onClicked: {
            label.text = "checkbox = " + target.checkState
        }
    }

    Connections {
        target: checkBox3
        onClicked: {
            label.text = "checkbox = " + target.checkState
        }
    }

    Connections {
        target: checkBox4
        onClicked: {
            label.text = "checkbox = " + target.checkState
        }
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}D{i:9}
}
##^##*/
