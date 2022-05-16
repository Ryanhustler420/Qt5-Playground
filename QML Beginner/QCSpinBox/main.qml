import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Grid {
        id: grid
        x: 0
        y: 0
        width: 214
        height: 40
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25
        columns: 2
        anchors.horizontalCenter: parent.horizontalCenter

        SpinBox {
            id: spinBox
            onValueModified : {
                label.text = value
            }
        }

        Label {
            id: label
            text: qsTr("0")
            font.pointSize: 25
            font.bold: true
        }
    }

//    Connections {
//        target: spinBox
//        onValueModified: {
//            label.text = target.value
//        }
//    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
