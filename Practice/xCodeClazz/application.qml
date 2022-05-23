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
    }

    //    header: Rectangle {
    //        height: 30
    //        width: parent.width
    //        color: "black"

    //        Label {
    //            id: title
    //            padding: 10
    //            color: "white"
    //            font.pointSize: 10
    //            anchors.verticalCenter: parent.verticalCenter
    //            text: qsTr("<b>x</b>CodeClazz")
    //        }

    //        MouseArea {
    //            id: titleBarMouseRegion
    //            property var clickPos
    //            anchors.fill: parent
    //            onPressed: {
    //                clickPos = { x: mousePosition.cursorPos().x, y: mousePosition.cursorPos().y }
    //            }
    //            onPositionChanged: {
    //                // x Y
    //                // 0 0
    //                // 20 40
    //                //                console.log(clickPos.x - root.x, clickPos.x, root.x)
    //                //                console.log(clickPos.y - root.y, clickPos.y, root.y)

    //                //                console.log(clickPos.x - (clickPos.x - root.x), root.x)
    //                //                console.log(clickPos.y - (clickPos.y - root.y), root.y)

    //                //                console.log(mousePosition.cursorPos().x - (mousePosition.cursorPos().x - root.x))
    //                //                console.log(mousePosition.cursorPos().y - (mousePosition.cursorPos().y - root.y))

    //                //                var newX = (clickPos.x - root.x)
    //                //                var newY = (clickPos.y - root.y)

    //                //                root.x =  mousePosition.cursorPos().x - newX
    //                //                root.y =  mousePosition.cursorPos().y - newY
    //            }
    //        }

    //        // root.x = 233
    //        // root.y = 94

    //        // cur.x = 662
    //        // cur.y = 114

    //        // click.x = 661
    //        // click.y = 114

    //    }

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
