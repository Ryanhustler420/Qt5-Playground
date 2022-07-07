import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

import com.application 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("File Upload")

    Column {
        anchors.centerIn: parent
        spacing: 10

        Button {
            text: "Send Single Image"
            onClicked: {
                page_controller.uploadSingleImage()
            }
        }

        Button {
            text: "Send Single File"
            onClicked: {
                page_controller.uploadSingleFile()
            }
        }

        Button {
            text: "Send Multiple Images"
            onClicked: {
                page_controller.uploadMultipleImages()
            }
        }

        Button {
            text: "Send Multiple Files"
            onClicked: {

            }
        }

    }

    ApplicationController {
        id: page_controller
    }

}
