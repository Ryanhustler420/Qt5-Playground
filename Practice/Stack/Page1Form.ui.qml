import QtQuick 2.12
import QtQuick.Controls 2.5

import software.raisehand.pageonecontroller 1.0

Page {
    width: 600
    height: 400

    title: qsTr("Page 1")

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }
}
