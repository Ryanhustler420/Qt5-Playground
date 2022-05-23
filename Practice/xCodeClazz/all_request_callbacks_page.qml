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

        DelayButton {
            delay: 5000
            text: "Clear Everything"
            anchors.rightMargin: 10
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            onActivated: {
                page_controller.removeAll()
                application.pop()
            }
        }

    }

    ListModel { id: callbacks_model }
    ListView {
        id: callbacks_listview
        clip: true
        spacing: 10
        topMargin: 15
        leftMargin: 15
        width: parent.width
        height: parent.height
        highlightFollowsCurrentItem: true
        onWidthChanged: {
            width: parent.width
            height: parent.height
        }
        model: callbacks_model
        delegate: Rectangle {
            width: callbacks_listview.width
            color: "transparent"
            height: 70
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
                        onClicked: {
                            page_controller.removeItem(index);
                        }
                    }

                    Button {
                        text: `Accept`
                        highlighted: true
                        Material.background: Material.Green
                        onClicked: {
                            page_controller.removeItem(index);
                        }
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
        onAllItemRemoved: {
            callbacks_model.clear()
        }
        onItemRemoved: {
            callbacks_model.remove(currentIndex)
        }
        onNewItemAdded: {
            callbacks_model.append(JSON.parse(JSON.stringify(object)))
        }
        Component.onCompleted: {
            page_controller.addNewItem({ course: "Python Code For Beginner", name: "Sikha Jha", school: "KPS Kadma", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "C++ Code For Beginner", name: "Vikram Pradhan", school: "KPS Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "Java Code For Beginner", name: "Anjali Gupta", school: "DAV Adityapur", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
            page_controller.addNewItem({ course: "NodeJs Code For Beginner", name: "Mahesh Gupta", school: "Xavier Gamharia", phone: "xxxxxxxxxx" })
        }
    }

}
