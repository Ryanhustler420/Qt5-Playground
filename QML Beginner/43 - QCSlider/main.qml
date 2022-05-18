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
        width: 535
        height: 103
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25
        anchors.horizontalCenter: parent.horizontalCenter

        Slider {
            id: slider
            width: 300
            stepSize: .1
            value: 0
        }

        Label {
            id: label
            font.bold: true
            font.pointSize: 25

            Connections {
                target: slider
                onMoved: label.text = Math.round(slider.value * 100)
            }

        }

//        Connections {
//            target: slider
//            onMoved: label.text = Math.round(slider.value * 100)
//        }

    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
