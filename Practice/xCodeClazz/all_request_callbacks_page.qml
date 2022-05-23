import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

import com.xcodeclazz.allrequestcallbackspage 1.0

Page {
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true
    title: qsTr("xCodeClazz")

    Component.onCompleted: {

    }

    header: Item {
        height: 70
        width: parent.width

        Label {
            id: title
            padding: 10
            font.bold: true
            font.pointSize: 30
            text: qsTr("Callback Requests")
            anchors.left: parent.left
        }

    }

    ListView {
        clip: true
        spacing: 10
        topMargin: 15
        leftMargin: 15
        width: parent.width
        height: parent.height
        onWidthChanged: {
            width: parent.width
            height: parent.height
        }
        model: ListModel {

            ListElement {
                course: "C++ Code For Beginner"
                name: "Vikram Pradhan"
                school: "KPS Gamharia"
                phone: "xxxxxxxxxx"
            }

            ListElement {
                course: "Java Code For Beginner"
                name: "Anjali Gupta"
                school: "DAV Adityapur"
                phone: "xxxxxxxxxx"
            }

            ListElement {
                course: "Python Code For Beginner"
                name: "Sikha Jha"
                school: "KPS Kadma"
                phone: "xxxxxxxxxx"
            }

            ListElement {
                course: "NodeJs Code For Beginner"
                name: "Mahesh Gupta"
                school: "Xavier Gamharia"
                phone: "xxxxxxxxxx"
            }

        }
        delegate: Rectangle {
            width: parent.width
            color: "transparent"
            height: 80

            Row {
                width: parent.width

                Column {
                    width: parent.width * .8

                    Label {
                        text: `${name}`
                        font.pointSize: 20
                        font.bold: false
                    }

                    Label {
                        color: "grey"
                        text: `${course}`
                        font.bold: true
                        font.pointSize: 10
                    }

                    Label {
                        text: `${school} • ${phone}`
                    }
                }

                Row {
                    anchors.verticalCenter: parent.verticalCenter
                    width: parent.width * .2
                    spacing: 5

                    Button {
                        text: `Delete`
                        highlighted: true
                        Material.background: Material.Red
                    }

                    Button {
                        text: `Accepted`
                        highlighted: true
                        Material.background: Material.Green
                    }

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

    AllRequestCallbacksPage {
        id: page_controller
    }

}
