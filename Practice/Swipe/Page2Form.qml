import QtQuick 2.9
import QtQuick.Controls 2.5

import com.pagetwocontroller 1.0

Page {
    width: 600
    height: 400

    title: qsTr("Page 2")

    Button {
        text: qsTr("Go To Page 1")
        anchors.centerIn: parent
        onClicked: {
            page_controller.schedule()
            application.pushPageOne()
        }
    }

    PageTwoController {
        id: page_controller
    }
}
