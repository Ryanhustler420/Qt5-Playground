import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        anchors.centerIn: parent
        spacing: 2
        MyShape { color: "red"; }
        MyShape { color: "blue"; }
        MyShape { color: "green"; }
    }

    Row {
        MyShape { color: "yellow"; }
        MyShape { color: "purple"; }
        MyShape { color: "cyan"; }
    }

}
