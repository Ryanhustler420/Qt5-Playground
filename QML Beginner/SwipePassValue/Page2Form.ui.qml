import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    id: page
    width: 600
    height: 400

    property alias name: myLabel.text

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 2.")
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Label {
        id: myLabel
        text: qsTr("Here")
        anchors.verticalCenter: parent.verticalCenter
        font.pointSize: 25
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
