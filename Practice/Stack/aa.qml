import QtQuick 2.12
import QtQuick.Controls 2.5

import software.raisehand.pageonecontroller 1.0

Page {
    width: 600
    height: 400

    title: qsTr("aa")

    PageOneController {
        id: controller
        onVersionChanged: {
            console.log(response)
        }
    }

    Label {
        text: qsTr("aa")
        anchors.centerIn: parent
    }

    Button {
        text: "SetVersion"
        onClicked: {
            controller.setVersion(25)
        }
    }

}
