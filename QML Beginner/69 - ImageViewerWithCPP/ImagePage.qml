import QtQuick 2.0
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Item {

    property alias source: image

    Page {
        anchors.fill: parent
        Image {
            id: image
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "https://via.placeholder.com/300x300"
        }
    }

}
