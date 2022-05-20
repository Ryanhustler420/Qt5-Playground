import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("xCodeClazz")

    StackView {
        id: stackview
        anchors.fill: parent
        initialItem: "login_page.qml"
    }

    Connections {
        target: application
        onClearedStack: {
            stackview.clear()
        }
        onPushPage: {
            stackview.push(qrc)
        }
    }

}
