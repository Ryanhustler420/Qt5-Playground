import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Abstract Button")

    AbstractButton {
        anchors.centerIn: parent
        height: 40
        width: 100
        text: "Fuck"
        font.italic: false
        font.bold: true
        checkable: true
        display: AbstractButton.IconOnly
        onClicked: {
            console.log("Fuck")
        }

        Label {
            text: "Hello"
            anchors.centerIn: parent
        }

    }

}
