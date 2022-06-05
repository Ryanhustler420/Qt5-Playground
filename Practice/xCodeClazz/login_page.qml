import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import com.xcodeclazz.loginpagecontroller 1.0

Page {
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true
    title: qsTr("xCodeClazz")

    Row {
        id: row
        anchors.fill: parent

        Column {
            id: column
            spacing: 5
            height: 200
            width: parent.width * .3
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

            Label {
                id: label
                width: parent.width
                Layout.alignment: Qt.AlignHCenter
                text: qsTr("<b>x</b>CodeClazz")
                horizontalAlignment: Text.AlignHCenter
                anchors.topMargin: 10
                font.pointSize: 20
            }

            TextField {
                id: tfEmail
                width: parent.width
                bottomPadding: 16
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                placeholderText: qsTr("Email")
            }

            TextField {
                id: tfPassword
                width: parent.width
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                placeholderText: qsTr("Password")
                echoMode: TextField.Password
            }

            Column {
                width: parent.width

                Button {
                    id: loginBtn
                    width: parent.width
                    text: "Login"
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter
                    onClicked: login()
                }

                Button {
                    id: googleLoginBtn
                    width: parent.width
                    text: "Continue with Google"
                    Layout.fillWidth: true
                    Layout.alignment: Qt.AlignHCenter
                    onClicked: loginWithGoogle()
                }

            }

        }
    }

    Action {
        shortcut: "return"
        onTriggered: {
            login()
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
            popup.close()
            if (isAuthenticated == true)
                application.replacePage(application.getDashboardPath())
        }
        onLoginSucced: {
            popup.close()
            application.gotoPage(application.getDashboardPath())
        }
        onLoginFailed: {
            popup.close()
        }
        onGoogleOauthSucced: {
            popup.close()
            application.gotoPage(application.getDashboardPath())
        }
        onGoogleOauthFailed: {
            popup.close()
        }
    }

    Component.onCompleted: {
        popup.open()
        page_controller.checkAuthentication()
    }

    function login() {
        popup.open()
        page_controller.login(tfEmail.text, tfPassword.text)
    }

    function loginWithGoogle() {
        popup.open()
        page_controller.oauthGoogleLogin();
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
