import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Application Window")

    menuBar: MenuBar {
        // ...
        MenuBarItem {
            text: "File"
        }
    }

    //    menuBar: Rectangle {
    //        height: 20
    //        width: parent.width
    //        color: "red"
    //        // ...
    //    }

    //    Duplicate Property Binding
    //    menuBar: MenuBar {
    //        // ...
    //    }

    //        header: ToolBar {
    //            spacing: 5
    //            ToolButton {
    //                text: "Copy"
    //            }
    //        }

    header: Rectangle {
        DelayButton {
            text: "Copy"
        }
        ToolButton {
            text: "Copy"
        }
    }

    footer: TabBar {
        TabButton {
            text: "First"
            onClicked: {
                stack.push("qrc:/chat.qml")
            }
        }
    }

    StackView {
        id: stack
        anchors.fill: parent
    }

}
