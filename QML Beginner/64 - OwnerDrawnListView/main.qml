import QtQuick 2.12
import QtQuick.Window 2.12

// Listview color list view
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        id: listView
        anchors.margins: 20
        anchors.fill: parent
        delegate: ColorDelegate {

        }
        model: ColorModel {

        }
    }

}
