import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Button Group")

    Grid {
        id: grid
        anchors.fill: parent
        spacing: 10
        columns: 3

        Rectangle {
            id: rectangle
            width: 200
            height: 200
            border.color: "red"

            ButtonGroup {
                buttons: columnOfButtons.children
                onClicked: {
                    console.log(button.text, button.checked)
                }
            }

            Column {
                anchors.centerIn: parent
                id: columnOfButtons

                RadioButton {
                    checked: true
                    text: "Panty"
                }

                RadioButton {
                    checked: false
                    text: "Bra"
                }

            }

        }

        Rectangle {
            id: rectangle1
            width: 200
            height: 200
            border.color: "green"

            ButtonGroup {
                id: groupOfButton
                onClicked: {
                    console.log(button.text, button.checked)
                }
            }

            Column {
                anchors.centerIn: parent

                RadioButton {
                    checked: true
                    text: "PS4"
                    ButtonGroup.group: groupOfButton
                }

                RadioButton {
                    checked: false
                    text: "XBox"
                    ButtonGroup.group: groupOfButton
                }

            }

        }

        Rectangle {
            id: rectangle2
            width: 200
            height: 200
            border.color: "purple"

            Text {
                anchors.centerIn: parent
                text: qsTr("text")
            }

        }

        Rectangle {
            id: rectangle3
            width: 200
            height: 200
            border.color: "blue"

            Text {
                anchors.centerIn: parent
                text: qsTr("text")
            }

        }

        Rectangle {
            id: rectangle4
            width: 200
            height: 200
            border.color: "black"

            ButtonGroup {
                id: buttonContainer
                buttons: column.children
                onClicked: {
                    console.log(button.text)
                    // buttonContainer.addButton({ text: "Red" }) // dont know why it's not working
                }
            }

            Column {
                id: column
                anchors.centerIn: parent
                Button { text: "First" }
                Button { text: "Second" }
                Button { text: "Third" }
            }

        }

        Rectangle {
            id: rectangle5
            width: 200
            height: 200
            border.color: "orange"

            Text {
                anchors.centerIn: parent
                text: qsTr("text")
            }

        }
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}
}
##^##*/
