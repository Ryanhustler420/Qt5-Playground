import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Group Box")

    GroupBox {
        label: CheckBox {
            id: all
            checked: false
            text: "All"
        }

        title: "Sync"

        Column {
            anchors.fill: parent
            enabled: all.checked
            CheckBox { text: "E-mail"; checked: all.checked }
            CheckBox { text: "Calendar"; checked: all.checked }
            CheckBox { text: "Contacts"; }
        }

    }

}
