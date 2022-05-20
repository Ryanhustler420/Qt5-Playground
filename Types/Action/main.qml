import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Action {
        id: sendMessage
        text: qsTr("&SendMessage")
        shortcut: "Return" // "Retur" won't work
        onTriggered: {
            console.log("Send Message");
        }
        ActionGroup.group: messageRelatedActions
    }

    Action {
        shortcut: "Ctrl+E"
        checkable: true // inToggleTriggers because of this
        enabled: true
        icon.name: "Combine"
        text: "Combine"
        onTriggered: {
            console.log("Combine Shortcut")
        }
        onToggled: {
            console.log(checked)
        }
    }

    ActionGroup {
        id: fileRelateActions

        Action {
            id: copyAction
            checked: false
            checkable: true
            text: qsTr("&Copy")
            shortcut: StandardKey.Copy
            onTriggered: {
                console.log("Copied")
                // window.activeFocusItem.copy()
            }
        }

    }

    ActionGroup {
        id: messageRelatedActions
    }

}
