import QtQuick 2.12
import QtQuick.Window 2.12
import QtGraphicalEffects 1.0

import com.QrClazz 1.0
import myextension 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QR Code")
    color: "#eeeeee"

    Rectangle {
        width: 200
        height: 200
        color: "white"
        anchors.centerIn: parent
        radius: 10

        ImageItem {
            id: ds
            smooth: true
            visible: false
            anchors.fill: parent
            anchors.centerIn: parent
            height: parent.height
            width: parent.width
        }

        DropShadow {
            anchors.fill: parent
            horizontalOffset: 0
            verticalOffset: 0
            color: "#ff000000"
            samples: 3
            radius: 1
            spread: .2
            source: ds
        }

    }

    Component.onCompleted: {
        ds.setImage(controller.convert("http://www.xcodeclazz.com"))
    }

    QrClazz {
        id: controller
    }

}
