import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Popup {
        id: popup
        anchors.centerIn: parent

        width: 200
        height: 200

        modal: true // focus, so user can't leave this popup and interact with other window
        focus: true // mouse, keyboard activity
        closePolicy: popup.CloseOnEscape | popup.CloseOnPressOutside // there are other condition as well


        Column {
            anchors.fill: parent
            spacing: 25

            Label {
                id: lblButter
                text: "Butter = " + chkButter.checked
            }

            Label {
                id: lblSyrup
                text: "Syrupr = " + chkSyrup.checked
            }

            Label {
                id: lblFruit
                text: "Fruit = " + chkFruit.checked
            }

            Button {
                text: qsTr("Close")
                onClicked: {
                    // popup.visible = false
                    popup.close()
                }
            }

        }

    }

    Frame {
        id: frame
        width: 149
        height: 276
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Column {
            id: column
            anchors.fill: parent
            spacing: 25

            CheckBox {
                id: chkButter
                text: qsTr("Butter")
            }

            CheckBox {
                id: chkSyrup
                text: qsTr("Syrup")
            }

            CheckBox {
                id: chkFruit
                text: qsTr("Fruit")
            }

            Button {
                id: button
                text: qsTr("Save")
                anchors.horizontalCenter: parent.horizontalCenter
                // onClicked: popup.visible = true
                onClicked: popup.open()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}
}
##^##*/
