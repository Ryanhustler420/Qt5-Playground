import QtQuick 2.9
import QtQuick.Controls 2.5

import com.pageonecontroller 1.0

Page {
    width: 600
    height: 400

    title: qsTr("Page 1")

    Button {
        text: qsTr("Go To Page 2")
        anchors.centerIn: parent
        onClicked: {
            page_controller.schedule()
            application.pushPageTwo()
        }
    }

    PageOneController {
        id: page_controller
    }
}
