import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Pane")

    //    Pane {
    //        ColumnLayout {
    //            anchors.fill: parent
    //            CheckBox { text: qsTr("E-mail") }
    //            CheckBox { text: qsTr("Calendar") }
    //            CheckBox { text: qsTr("Contacts") }
    //        }
    //    }

    //    Pane {
    //        SwipeView {
    //            // ...
    //        }
    //        PageIndicator {
    //            anchors.horizontalCenter: parent.horizontalCenter
    //            anchors.bottom: parent.bottom
    //        }
    //    }

    //    Pane {
    //        contentWidth: view.implicitWidth
    //        contentHeight: view.implicitHeight

    //        SwipeView {
    //            id: view
    //            // ...
    //        }
    //        PageIndicator {
    //            anchors.horizontalCenter: parent.horizontalCenter
    //            anchors.bottom: parent.bottom
    //        }
    //     }

    Pane {
        Item {
            Rectangle {
                implicitWidth: 200
                implicitHeight: 200
                color: "salmon"
            }
        }
    }

}
