import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ComboBox")

    ComboBox {
        id: comboBox
        model: ["First", "Second", "Third"]
        // editable: true
        delegate: Row {
            width: parent.width
            height: 40

            Rectangle {
                id: item
                width: parent.width
                height: 40

                Text {
                    anchors.verticalCenter: parent.verticalCenter
                    padding: 10
                    text: modelData
                    id: title
                }

                MouseArea {
                    anchors.fill: parent
                    hoverEnabled: true
                    onEntered: {
                        item.color = "gray";
                    }
                    onExited: {
                        item.color = "white";
                    }
                    onClicked: {
                        comboBox.currentIndex = comboBox.model.indexOf(title.text)
                        comboBox.popup.close()
                    }
                }

            }

        }

    }

}
