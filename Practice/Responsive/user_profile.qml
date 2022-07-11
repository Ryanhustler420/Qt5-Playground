import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    visible: true
    width: 800; height: 500
    minimumWidth: 300; minimumHeight:  400

    Component.onCompleted: {
        pop.open()
    }

    Popup {
        id: pop
        width: 300
        padding: 0
        clip: true
        modal: true
        focus: true
        anchors.centerIn: parent
        closePolicy: Popup.CloseOnEscape | Popup.NoAutoClose

        Column {
            width: parent.width

            Column {
                width: parent.width
                padding: 10

                Row {
                    spacing: 10

                    Image {
                        width: 50
                        id: user_avatar
                        fillMode: Image.PreserveAspectFit
                        height: user_meta_details_col.height
                        source: "http://xcodeclazz.com/assets/logo192.png"
                    }

                    Column {
                        width: parent.width - user_avatar.width
                        id: user_meta_details_col
                        spacing: 5

                        Label {
                            text: "Gaurav Gupta"
                            font.pointSize: 15
                            font.bold: true
                        }

                        Label {
                            text: "+91 9835718631"
                            font.pointSize: 8
                        }

                    }

                }

            }

            Rectangle {
                width: parent.width
                color: "#23252F"
                height: 40
            }

            Column {
                width: pop.width
                padding: 10
                spacing: 10

                TextField {
                    width: parent.width - 20
                    placeholderText: "Name"
                }

                TextField {
                    width: parent.width - 20
                    placeholderText: "Phone Number"
                }

                TextField {
                    width: parent.width - 20
                    placeholderText: "Other Field"
                }

            }

            Rectangle {
                width: parent.width
                color: "#23252F"
                height: 100
            }

            Rectangle {
                width: parent.width
                color: "transparent"
                height: 50

                Label {
                    text: "UPDATE"
                    font.bold: true
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        pop.close()
                    }
                }

            }

        }

    }

}
