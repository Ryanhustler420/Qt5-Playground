import QtQuick 2.0

// Right Click on project root > Add New > Qt > QML FIle (qt quick 2) > (name)[MyShape] > Finish

Rectangle {
    color: "gray"
    width: 100
    height: 100

    MouseArea {
        anchors.fill: parent
        drag.target: parent
        onClicked: parent.z = parent.z + 1 // parent.z++
    }

}
