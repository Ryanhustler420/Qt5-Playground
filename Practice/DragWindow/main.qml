import QtQuick 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

ApplicationWindow {
    id: appWindow
    visible: true
    width: 800
    height: 400
    flags: Qt.Window|Qt.FramelessWindowHint

    header: Rectangle {
        id: title_bar
        color: "blue"
        height: 30

        Label {
            anchors.margins: 10
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            text: "Window Drag:: Application"
            font.bold: true
            color: "white"
        }

        MouseArea {
            id: mouseRegion
            anchors.fill: parent;
            property variant clickPos: "1,1"
            property variant appStartPos: "1,1"

            onPressed: {
                // fetch global position due to bug on ubuntu
                clickPos = gApplicationController.getCursorPos()
                appStartPos = Qt.point(appWindow.x, appWindow.y)
            }

            onPositionChanged: {
                var newPos = gApplicationController.getCursorPos()
                var delta = Qt.point(newPos.x-clickPos.x, newPos.y-clickPos.y)
                appWindow.x = appStartPos.x+delta.x;
                appWindow.y = appStartPos.y+delta.y;
            }
        }

    }

}
