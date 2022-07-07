import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

ApplicationWindow {
    id: root
    width: 900
    height: 550
    visible: true
    title: qsTr("xCodeClazz")
    // flags: Qt.FramelessWindowHint | Qt.Window

    StackView {
        id: stackview
        anchors.fill: parent
        initialItem: application.getLoginPagePath()

        pushEnter: Transition {
            id: pushEnter
            ParallelAnimation {
                PropertyAction { property: "x"; value: pushEnter.ViewTransition.item.pos }
                NumberAnimation { properties: "y"; from: pushEnter.ViewTransition.item.pos + stackView.offset; to: pushEnter.ViewTransition.item.pos; duration: 400; easing.type: Easing.OutCubic }
                NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 400; easing.type: Easing.OutCubic }
            }
        }
        popExit: Transition {
            id: popExit
            ParallelAnimation {
                PropertyAction { property: "x"; value: popExit.ViewTransition.item.pos }
                NumberAnimation { properties: "y"; from: popExit.ViewTransition.item.pos; to: popExit.ViewTransition.item.pos + stackView.offset; duration: 400; easing.type: Easing.OutCubic }
                NumberAnimation { property: "opacity"; from: 1; to: 0; duration: 400; easing.type: Easing.OutCubic }
            }
        }
        pushExit: Transition {
            id: pushExit
            PropertyAction { property: "x"; value: pushExit.ViewTransition.item.pos }
            PropertyAction { property: "y"; value: pushExit.ViewTransition.item.pos }
        }
        popEnter: Transition {
            id: popEnter
            PropertyAction { property: "x"; value: popEnter.ViewTransition.item.pos }
            PropertyAction { property: "y"; value: popEnter.ViewTransition.item.pos }
        }
    }

    ProgressBar {
        id: app_n_progress_bar
        visible: false
        value: .5
        from: .1
        indeterminate: true
        width: parent.width
    }

    RoundButton {
        text: "<<"
        font.bold: true
        anchors.margins: 10
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        visible: hasStack()
        onClicked: {
            pop()
        }
        ToolTip.visible: down
        ToolTip.text: "Back"
    }
    Connections {
        target: application
        onClearedStack: {
            stackview.clear()
        }
        onLoading: {
            app_n_progress_bar.visible = b;
        }
        onPushPage: {
            stackview.push(qrc)
        }
        onPageReplaced: {
            stackview.replace(qrc)
        }
        onPoped: {
            pop()
        }
    }

    Action {
        shortcut: "ctrl+backspace"
        enabled: hasStack()
        onTriggered: {
            pop()
        }
    }

    function hasStack() {
        return stackview.depth > 1;
    }

    function pop() {
        stackview.pop()
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
