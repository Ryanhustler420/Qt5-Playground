import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Overlay")

    Button {
        onClicked: popup.open()

        Popup {
            id: popup

            parent: Overlay.overlay

            x: Math.round((parent.width - width) / 2)
            y: Math.round((parent.height - height) / 2)
            width: 100
            height: 100

            modal: true
            visible: true
            Overlay.modal: Rectangle {
                color: "#aacfdbe7"
            }

        }

    }

}
