import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string username: "gauravgupta"
    property string password: "123456789"
    property string status: "Failed"

    Popup {
        id: statusPopup
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        modal: true
        focus: true
        anchors.centerIn: parent
        width: 200
        height: 300

        Label {
            id: statusLabel
            anchors.centerIn: parent
            font.bold: true
            text: status
        }
    }

    Column {
        id: column
        x: 0
        y: 0
        width: 277
        height: 155
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Grid {
            id: grid
            width: 300
            height: 100
            spacing: 10
            columns: 2

            Label {
                id: label
                text: qsTr("Username")
            }

            TextField {
                id: txtUsername
                text: qsTr("")
            }

            Label {
                id: label1
                text: qsTr("Password")
            }

            TextField {
                id: txtPassword
                echoMode: TextInput.Password
            }
        }

        Button {
            id: button
            text: qsTr("Login")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                if (username === txtUsername.text && password === txtPassword.text) {
                    status = "Welcome"
                }
                statusPopup.open()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}
}
##^##*/
