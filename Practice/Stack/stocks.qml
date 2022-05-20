import QtQuick 2.12
import QtQuick.Controls 2.5

import software.raisehand.stockcontroller 1.0

Page {
    width: 600
    height: 400
    title: qsTr("Raisehand | Stocks")

    StockController {
        id: controller
    }

    Label {
        text: qsTr("Render Stocks")
        anchors.centerIn: parent
    }

    Button {
        text: "Get Stocks"
        onClicked: {
            controller.setVersion(25)
        }
    }

}
