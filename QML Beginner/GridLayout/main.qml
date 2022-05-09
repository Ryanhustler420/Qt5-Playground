import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Grid {
        anchors.centerIn: parent
        spacing: 5
        columns: 4
        rows: 3

        MyShape { color: "red"; }
        MyShape { color: "blue"; }
        MyShape { color: "yellow"; }
        MyShape { color: "green"; }
        MyShape { color: "purple"; }
        MyShape { color: "cyan"; }
        MyShape { color: "black"; }
        Rectangle {
            width: 50
            height : 100
            color: "brown"
        }
        Rectangle {
            width: 50
            height : 100
            color: "orange"
        }
    }

}
