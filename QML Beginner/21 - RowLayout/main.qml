import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        anchors.centerIn: parent
        spacing: 2
        MyShape { color: "yellow"; }
        MyShape { color: "purple"; }
        MyShape { color: "cyan"; }
    }

}
