import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 200
        height: 400
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25
        anchors.horizontalCenter: parent.horizontalCenter

        CoolButton {
            id: downCoolBtn
            width: 100
            height: 100
            source: "qrc:/images/images/down-arrow.png"
            onClicked: {
                console.log("Down Clicked");
            }
        }

        CoolButton {
            id: upCoolBtn
            width: 100
            height: 100
            source: "qrc:/images/images/up-arrow.png"
            onClicked: {
                console.log("Up Clicked");
            }
        }
    }
}
