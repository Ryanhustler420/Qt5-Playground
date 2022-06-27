import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

import com.app.application 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Drop Area")

    Label {
        id: msg
        visible: false
        text: "Drop Here"
        font.pointSize: 25
        anchors.centerIn: parent
    }

    DropArea {
        id: dropArea;
        anchors.fill: parent
        onEntered: {
            msg.visible = true
            root.color = "#aa000000";
            drag.accept (Qt.LinkAction);
            page_controller.takeFiles(drag.urls);
        }
        onDropped: {
            // console.log(drop.urls)
            root.color = "white"
            msg.visible = false
        }
        onExited: {
            root.color = "white";
            msg.visible = false
        }
    }

    Popup {
        id: message_popup
        width: 400
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
        anchors.centerIn: parent

        Label {
            anchors.centerIn: parent
            text: "It's correct"
            font.pointSize: 25
        }
    }

    Application {
        id: page_controller
        onCorrectFileImported: {
            message_popup.open()
        }
    }

}
