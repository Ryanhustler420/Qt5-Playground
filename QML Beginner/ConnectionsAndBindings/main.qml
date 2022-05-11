import QtQuick 2.12
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    property alias mouseArea: mouseArea
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 120
        y: 182
        width: 125
        height: 117
        color: "#ff1e1e"

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }

        Connections {
            target: rectangle
            onClicked: {
                print("Clicked")
                rectangle.width = 50;
                rectangle.height = 150;
            }
        }

    }

    Rectangle {
        id: rectangle1
        x: 148
        y: 0
        width: rectangle.height
        height: rectangle.width
        color: "#4cd419"
    }

    Rectangle {
        id: rectangle2
        x: 294
        y: 0
        width: 125
        height: 117
        color: "#12279b"
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}D{i:2}
}
##^##*/
