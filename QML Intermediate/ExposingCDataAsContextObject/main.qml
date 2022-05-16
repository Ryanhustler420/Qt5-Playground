import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Context Object Demo")

    Rectangle {

        id: mRect1
        width: mText1.implicitWidth + 20
        height: mText1.implicitHeight + 20
        color: "beige"
        border.color: "yellowgreen"

        Text {
            id: mText1
            text: firstName // from Q_PROPERTY
            font.pointSize: 25
            anchors.centerIn: parent
        }
    }

    Rectangle {

        id: mRect2
        width: mText2.implicitWidth + 20
        height: mText2.implicitHeight + 20
        color: "beige"
        anchors.left: mRect1.right
        anchors.leftMargin: 5
        border.color: "yellowgreen"

        Text {
            id: mText2
            text: lastName // from Q_PROPERTY
            font.pointSize: 25
            anchors.centerIn: parent
        }

    }


}
