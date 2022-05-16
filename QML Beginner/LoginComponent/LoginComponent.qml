import QtQuick 2.0
import QtQuick.Controls 2.3

Item {

    signal login(string username, string password)
    width: 200
    height: 200

    Column {
        id: column
        anchors.fill: parent
        spacing: 10

        Label {
            id: txtUsername
            text: qsTr("Username")
        }

        TextField {
            id: txtFieldUsername
            width: parent.width
            text: qsTr("")
        }

        Label {
            id: txtPassword
            text: qsTr("Password")
        }

        TextField {
            id: txtFieldPassword
            width: parent.width
            echoMode: TextInput.Password
            text: qsTr("")
        }

        Button {
            id: button
            width: parent.width
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("Submit")
        }

    }

    Connections {
        target: button
        onClicked: login(txtFieldUsername.text, txtFieldPassword.text)
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}
}
##^##*/
