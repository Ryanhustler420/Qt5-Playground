import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    visible: true
    width: 800; height: 500
    minimumWidth: 300; minimumHeight:  400

    readonly property int responsiveWidth: 500

    Item {
        states: [
            State {
                when: window.width <= responsiveWidth
                PropertyChanges {
                    target: oauth_column
                    parent: oauth_column_container
                }
                PropertyChanges {
                    target: login_form_column
                    parent: login_form_column_container
                }
            }
        ]
    }

    Row {
        anchors.fill: parent

        Item {
            id: left
            width: parent.width * .5
            height: parent.height

            Rectangle {
                anchors.fill: parent
                color: "transparent"

                Column {
                    id: oauth_column
                    spacing: 10
                    anchors.centerIn: parent

                    Label {
                        text: "One Network.\nRaisehand"
                        font.pointSize: 30
                    }

                    Row {

                        RoundButton {
                            text: "G"
                        }

                        RoundButton {
                            text: "F"
                        }

                    }

                }

            }

        }

        Item {
            id: right
            width: parent.width * .5
            height: parent.height

            Rectangle {
                anchors.fill: parent
                color: "transparent"

                Column {
                    id: login_form_column
                    width: parent.width
                    anchors.centerIn: parent
                    spacing: 10
                    states: [
                        State {
                            when: window.width > 600
                            PropertyChanges {
                                target: username_txt_field
                                width: parent.width * .6
                            }
                            PropertyChanges {
                                target: password_txt_field
                                width: parent.width * .6
                            }
                            PropertyChanges {
                                target: cta_row
                                width: parent.width * .6
                            }
                        }
                    ]

                    TextField {
                        id: username_txt_field
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width * .9
                        placeholderText: "Username"
                    }

                    TextField {
                        id: password_txt_field
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width * .9
                        placeholderText: "Password"
                        echoMode: TextField.Password
                    }

                    Row {
                        id: cta_row
                        anchors.horizontalCenter: parent.horizontalCenter
                        width: parent.width * .9

                        CheckBox {
                            checked: true
                            text: "Keep me login"
                            width: parent.width - login_btn.width
                        }

                        Button {
                            id: login_btn
                            text: "Login"
                        }

                    }

                }

            }

        }

    }

    Column {
        anchors.fill: parent
        Item { id: oauth_column_container; width: parent.width; height: parent.height * .5 }
        Item { id: login_form_column_container; width: parent.width; height: parent.height * .5 }
    }

}
