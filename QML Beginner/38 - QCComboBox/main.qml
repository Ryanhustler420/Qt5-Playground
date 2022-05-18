import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        x: 63
        y: 40
        width: 181
        height: 192
        anchors.verticalCenter: parent.verticalCenter
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: lblFood
            color: "#de102b"
            text: qsTr("Selected Item")
            font.letterSpacing: 1
            horizontalAlignment: Text.AlignLeft
            font.pointSize: 8
            font.bold: true
        }

        ComboBox {
            id: cmbFood
            anchors.horizontalCenter: parent.horizontalCenter
            model: ["Pizza", "Burger", "Rice", "Bread"] // under the hood this is being converted into ListModel as well

            onCurrentTextChanged: lblFood.text = cmbFood.currentText
        }

        Label {
            id: lblPeople
            color: "#de102b"
            text: qsTr("Label")
            font.letterSpacing: 1
            horizontalAlignment: Text.AlignLeft
            font.pointSize: 8
            font.bold: true
        }

        ComboBox {
            id: cmbPeople
            anchors.horizontalCenter: parent.horizontalCenter

            editable: true
            textRole: "text" // name
            // currentIndex: 2
            model: ListModel {
                  id: listmodel
                  ListElement {
                      text: "Bryan" // name: "Bryan"
                      age: "45"
                  }
                  ListElement {
                      text: "Tammy"
                      age: "40"
                  }
                  ListElement {
                      text: "Rango"
                      age: "15"
                  }
            }
            onCurrentIndexChanged: lblPeople.text = model.get(currentIndex).text + " = " + model.get(currentIndex).age
            onAccepted: {
                if (find(editText) === -1) {
                    model.append({ "text": editText, "age": "0" })
                    currentIndex = find(editText)
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
