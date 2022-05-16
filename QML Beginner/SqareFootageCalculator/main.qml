import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function calc() {
        var num = sbWidth.value * sbHeight.value
        label.text = `${num} sqft`
    }

    Column {
        id: column
        width: 200
        height: 132
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: label
            text: qsTr("0 sqft")
            font.bold: true
            font.pointSize: 25
        }

        Grid {
            id: grid
            width: 400
            height: 400
            rows: 2
            columns: 2
            spacing: 10

            Label {
                id: label1
                text: qsTr("Width")
            }

            SpinBox {
                id: sbWidth
            }

            Label {
                id: label2
                text: qsTr("Height")
            }

            SpinBox {
                id: sbHeight
            }
        }
    }

    Connections {
        target: sbWidth
        onValueModified: calc()
    }

    Connections {
        target: sbHeight
        onValueModified: calc()
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:3}
}
##^##*/
