import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

ColumnLayout {
    id: root

    property alias $root: root

    property int $preferredHeight: 100
    property int $preferredWidth: 100

    property int $height: 100
    property int $width: 100

    Layout.preferredHeight: $preferredHeight * scale_factor
    Layout.preferredWidth: $preferredWidth * scale_factor
    height: $height * scale_factor
    width: $width * scale_factor
    Layout.fillHeight: true
    Layout.fillWidth: true

    Image {
        source: "https://via.placeholder.com/500"

        Layout.preferredWidth: parent.width
        Layout.preferredHeight: 80
        Layout.fillHeight: true
        Layout.fillWidth: true
    }

    Rectangle {
        Layout.preferredWidth: parent.width
        Layout.preferredHeight: 20
        Layout.fillHeight: true
        Layout.fillWidth: true
        color: "white"
    }

}
