import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        anchors.fill: parent

        Image {
            id: image
            width: 300
            height: 300
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/qtquickplugin/images/template_image.png"
            fillMode: Image.PreserveAspectFit
        }

        Switch {
            id: switch1
            text: qsTr("Sad")
            anchors.bottom: image.top
            checkable: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 50
            onToggled: {
                if (checked) {
                    text = "Happy"
                    image.source = "qrc:/images/images/IMG_5075.JPG"
                } else {
                    text = "Sad"
                    image.source = "qrc:/images/images/IMG_5076.JPG"
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}
}
##^##*/
