import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import com.xcodeclazz.loginpagecontroller 1.0

Page {
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true
    title: qsTr("xCodeClazz")

    Component.onCompleted: {
        popup.open()
        page_controller.checkAuthentication()
    }

    RowLayout {
        id: row
        anchors.fill: parent

        ColumnLayout {
            id: column
            spacing: 10
            width: (parent.width * .3)
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

            Label {
                id: label
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("<b>x</b>CodeClazz")
                anchors.topMargin: 10
                width: parent.width
                font.pointSize: 20
            }

            TextField {
                id: tfEmail
                width: parent.width
                Layout.alignment: Qt.AlignHCenter
                placeholderText: qsTr("Email")
            }

            TextField {
                id: tfPassword
                width: parent.width
                Layout.alignment: Qt.AlignHCenter
                placeholderText: qsTr("Password")
                echoMode: TextField.Password
            }

            Button {
                id: loginBtn
                text: "Login"
                width: tfPassword.width
                Layout.alignment: Qt.AlignHCenter
                onClicked: {
                    popup.open()
                    page_controller.login(tfEmail.text, tfPassword.text)
                }
            }
        }
    }

    Popup {
        id: popup
        modal: true
        focus: true
        anchors.centerIn: parent
        closePolicy: Popup.NoAutoClose

        Label {
            anchors.centerIn: parent
            text: "Loading\u2026"
            font.pointSize: 12
        }
    }

    LoginPageController {
        id: page_controller
        onUserAuthenticated: {
            console.log(isAuthenticated)
            popup.close()
        }
        onLoginSucced: {
            popup.close()
            application.replacePage(application.getDashboardPath())
        }
    }

}
