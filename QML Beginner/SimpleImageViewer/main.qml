import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    id: root

    property color bgColor: "#5A6263"
    property color btnColor: "green"
    property color hoverColor: "limegreen"
    property color clickColor: "yellow"
    property real size: 100

    Rectangle {
        id: background
        color: root.bgColor
        width: 100
        height: parent.height

        Column {
            id: column
            anchors.fill: parent

            HoverButton {
                width: 100
                height: 50
                title.text: "1st Image"
                color: root.btnColor
                hoverColor: root.hoverColor
                clickColor: root.clickColor
                area.onPressed: imageComponent.source = "qrc:/images/IMG_5061.JPG";
            }

            HoverButton {
                width: 100
                height: 50
                title.text: "2nd Image"
                color: root.btnColor
                hoverColor: root.hoverColor
                clickColor: root.clickColor
                area.onPressed: imageComponent.source = "qrc:/images/IMG_5085.JPG";
            }

            HoverButton {
                width: 100
                height: 50
                title.text: "3rd Image"
                color: root.btnColor
                hoverColor: root.hoverColor
                clickColor: root.clickColor
                area.onPressed: imageComponent.source = "qrc:/images/IMG_5090.JPG";
            }
        }

    }

    Rectangle {
        id: rectangle
        x: 100
        y: 0
        color: root.bgColor
        width: parent.width - x
        height: parent.height

        Image {
            id: imageComponent
            source: "qrc:/images/IMG_5061.JPG"
            fillMode: Image.PreserveAspectFit
            anchors.margins: 25
            anchors.fill: parent
        }

    }

}
