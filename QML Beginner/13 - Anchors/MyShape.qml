import QtQuick 2.0

// Right Click on project root > Add New > Qt > QML FIle (qt quick 2) > (name)[MyShape] > Finish

// Correct Way
Item {
    id: root
    property color color: "gray"
    property string text: "title"

    width: 100
    height: 100

    Rectangle {
        color: root.color
        anchors.fill: parent // comment this when uncomment w/h
        //        width: 50
        //        height: 50

        Text {
            text: root.text
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
            drag.target: root.parent // when w/h uncommented make this 'parent'
            onClicked: root.z++
        }

    }
}

// Wrong Way
// Rectangle {
//    color: "gray"
//    width: 100
//    height: 100

//    property string $text: ""

//    Text {
//        id: name
//        text: parent.$text
//    }

//    MouseArea {
//        anchors.fill: parent
//        drag.target: parent
//        onClicked: parent.z = parent.z + 1 // parent.z++
//    }

// }
