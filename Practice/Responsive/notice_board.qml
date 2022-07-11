import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    visible: true
    width: 800; height: 500
    minimumWidth: 300; minimumHeight:  400

    property int messageCount: 0
    property int messageLimit: 180

    Component.onCompleted: {
        pop.open()
    }

    Popup {
        id: pop
        width: 300
        padding: 0
        modal: true
        focus: true
        clip: true
        anchors.centerIn: parent
        closePolicy: Popup.CloseOnEscape | Popup.NoAutoClose

        Column {
            width: pop.width

            Column {
                width: parent.width
                padding: 10
                spacing: 5

                Label {
                    text: "Notice Board"
                    font.pointSize: 20
                    font.bold: true
                }

                Label {
                    width: parent.width
                    wrapMode: Label.Wrap
                    text: "Get 50% off on the cipla C225L Tablets"
                    font.pointSize: 8
                }

            }

            Rectangle {
                width: pop.width
                color: "#23252F"
                height: 20
            }

            ScrollView {
                clip: true
                height: 150
                width: pop.width
                contentWidth: -1
                ScrollBar.horizontal: ScrollBar {
                    height: 0
                }
                ScrollBar.vertical: ScrollBar {
                    height: 0
                }

                TextArea {
                    placeholderText: "Write your message here..."
                    wrapMode: TextArea.WrapAnywhere
                    width: pop.width
                    padding: 10
                    onTextChanged: {
                        if (length > window.messageLimit) remove(window.messageLimit, length);

                        window.messageCount = length
                        count_state_label.text = `${window.messageCount}/${window.messageLimit}`;
                    }
                }

            }

            Row {
                width: pop.width
                padding: 5

                Label {
                    text: `${window.messageCount}/${window.messageLimit}`
                    anchors.verticalCenter: parent.verticalCenter
                    width: parent.width - publish_btn.width - 10
                    id: count_state_label
                    font.pointSize: 15
                }

                RoundButton {
                    id: publish_btn
                    text: "\u25B6"
                    onClicked: pop.close()
                }
            }

        }

    }

}
