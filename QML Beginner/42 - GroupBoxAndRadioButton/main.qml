import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string strDrink: ""
    property string strFood: ""

    Popup {
        id: popup
        anchors.centerIn: parent
        width: 200
        height: 200

        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Column {
            anchors.fill: parent
            spacing: 25
            Label {
                id: lblDetails
                text: strFood + " with " + strDrink
            }
            Button {
                id: closeButton
                text: "Close"
                onClicked: {
                    popup.close()
                }
            }
        }

    }

    Row {
        id: row
        x: 5
        y: 8
        width: 540
        height: 196
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25
        anchors.horizontalCenter: parent.horizontalCenter

        GroupBox {
            id: groupBox
            width: 200
            height: 190
            title: qsTr("Food")

            Column {
                id: columnFoods
                anchors.fill: parent
                spacing: 5

                RadioButton {
                    id: rbFish
                    text: qsTr("Fish")
                }

                RadioButton {
                    id: rbSteak
                    text: qsTr("Steak")
                }

                RadioButton {
                    id: rbVegan
                    text: qsTr("Vegan")
                }
            }
        }

        GroupBox {
            id: groupBox1
            x: 250
            width: 200
            height: 190
            Column {
                id: columnDrinks
                anchors.fill: parent
                spacing: 5
                RadioButton {
                    id: rbWater
                    text: qsTr("Water")
                }

                RadioButton {
                    id: rbWine
                    text: qsTr("Wine")
                }

                RadioButton {
                    id: rbSoda
                    text: qsTr("Soda")
                }
            }
            title: qsTr("Drinks")
        }
    }

    Button {
        id: button
        x: 228
        y: 376
        width: 100
        height: 27
        text: qsTr("Click Me")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Connections {
        target: button
        onClicked: {
            // get the food
            for (var i = 0; i < columnFoods.children.length; i++) {
                var rb = columnFoods.children[i]
                if (rb.checked) strFood = rb.text
            }

            // get the drink
            for (var k = 0; k < columnDrinks.children.length; k++) {
                var rb = columnDrinks.children[k]
                if (rb.checked) strDrink = rb.text
            }

            popup.open()
        }
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
