import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import software.raisehand.boxsetcontroller 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("BoxSet Window")

    BoxSetController {
        id: box_set_controller
        onGetChanged: {
            console.log(a)
        }
        onJsonChanged: {
            console.log(v1, v2)
        }
    }

    Button {
        id: clickBtn
        text: "Click"
        anchors.centerIn: parent
        onClicked: {
            box_set_controller.setGet(25)
            box_set_controller.setJson("This is it")
        }
    }

    Button {
        id: settingsBtn
        text: "Settings"
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: clickBtn.bottom
        onClicked: {
            // invoke a function which should open a new dialog and wait for that to finish
        }
    }

}
