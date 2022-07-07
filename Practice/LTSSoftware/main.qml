import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        anchors.centerIn: parent
        text: "Click Me"
        onClicked: {
            pop.open()
        }
    }

    Popup {
        id: pop
        width: 400
        height: 100
        modal: true
        focus: true
        anchors.centerIn: parent
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Label {
            text: "Working"
            font.bold: true
            font.pointSize: 20
            anchors.centerIn: parent
        }
    }

}
