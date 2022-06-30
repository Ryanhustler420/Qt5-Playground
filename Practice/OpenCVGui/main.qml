import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

import com.application 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("OpenCV")

    Column {
        anchors.centerIn: parent
        spacing: 10
        width: 400
        clip: true

        TextField {
            id: field
            placeholderText: "Enter Image Path"
            width: parent.width
        }

        Button {
            text: "See"
            onClicked: {
                controller.load(field.text)
            }
        }

    }

    ApplicationController {
        id: controller
    }

}
