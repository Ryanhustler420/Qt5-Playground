import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    visible: true
    width: 800; height: 500
    minimumWidth: 300; minimumHeight:  400

    property bool loadingPayment: false

    Component.onCompleted: {
        pop.open()
    }

    Popup {
        id: pop
        width: 300
        clip: true
        padding: 0
        modal: true
        focus: true
        anchors.centerIn: parent
        closePolicy: Popup.CloseOnEscape | Popup.NoAutoClose

        Column {
            width: parent.width

            Column {
                width: parent.width
                padding: 10
                spacing: 5

                Label {
                    font.pointSize: 20
                    text: "Payments"
                    font.bold: true
                }

                Label {
                    text: "Last payment on 65 days ago."
                    font.pointSize: 8
                }

            }

            Rectangle {
                width: parent.width
                color: "#23252F"
                height: 10
            }

            BusyIndicator {
                width: 100
                height: 100
                running: true
                antialiasing: true
                visible: loadingPayment
                anchors.horizontalCenter: parent.horizontalCenter
            }

            ListView {
                model: 10
                clip: true
                height: 300
                width: parent.width
                visible: (loadingPayment == false)
                delegate: Row {
                    height: 100

                    Rectangle {
                        color: "black"
                        anchors.fill: parent

                        Column {
                            spacing: 5
                            padding: 10
                            width: parent.width

                            Label {
                                text: "1452dbfjk5500"
                            }

                            Label {
                                text: "Payment Amount"
                                font.pointSize: 12
                                font.bold: true
                            }

                            Label {
                                text: "12-May-2022"
                            }

                        }
                    }
                }
            }

            Rectangle {
                width: parent.width
                color: "#23252F"
                height: 10
            }

            Rectangle {
                width: parent.width
                color: "transparent"
                height: 50

                Label {
                    text: "CLOSE"
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
