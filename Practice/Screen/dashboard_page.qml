import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.0

import QtQuick.Controls.Material 2.3

ApplicationWindow {
    id: root
    width: 1200
    height: 720
    visible: true
    title: qsTr("Dashboard")

    Row {
        anchors.fill: parent

        // First Column
        Column {
            width: parent.width
            height: parent.height

            ListView {
                width: parent.width
                height: parent.height
                model: 100
                delegate: ItemDelegate {
                    width: parent.width
                    text: modelData
                }
            }

        }

        // Second Column
        Column {
            // ...
        }

    }

}
