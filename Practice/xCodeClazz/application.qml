import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 900
    height: 550
    visible: true
    title: qsTr("xCodeClazz")

    StackView {
        id: stackview
        anchors.fill: parent
        initialItem: application.getLoginPagePath()
    }

    RoundButton {
        text: "<<"
        font.bold: true
        anchors.margins: 10
        highlighted: true
        flat: false
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        visible: stackview.depth > 1
        onClicked: {
            stackview.pop()
        }
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
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
