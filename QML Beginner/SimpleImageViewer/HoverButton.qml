import QtQuick 2.0

Item {
    id: root
    property color color: "red"
    property color textColor: "white"
    property color hoverColor: "pink"
    property color clickColor: "orange"
    property color textHoverColor: "black"
    property alias title: displayComponent // nick name kinda *pointer of c++
    property alias area: mouseAreaComponent // use it to expose the component properties

    Rectangle {
        height: root.height
        width: root.width
        color: root.color
        clip: true

        Text {
            id: displayComponent
            text: ""
            anchors.centerIn: parent
            color: root.textColor
            font.bold: true
        }

        MouseArea {
            id: mouseAreaComponent
            anchors.fill: parent
            hoverEnabled: true

            onEntered: {
                parent.color = root.hoverColor
                displayComponent.color = root.textHoverColor
            }

            onExited: {
                parent.color = root.color
                displayComponent.color = root.textColor
            }

            onPressed: {
                parent.color = root.clickColor;
            }
            onReleased: {
                parent.color = root.hoverColor;
            }

        }

    }




}
