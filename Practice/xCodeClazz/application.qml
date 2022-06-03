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

    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSans-Black.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSans-Bold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSans-ExtraBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSans-Light.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSans-Medium.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSans-Regular.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSans-SemiBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSans-Thin.ttf" }

    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansCondensed-Black.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansCondensed-Bold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansCondensed-ExtraBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansCondensed-ExtraLight.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansCondensed-Light.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansCondensed-Medium.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansCondensed-Regular.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansCondensed-SemiBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansCondensed-Thin.ttf" }

    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansExpanded-Black.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansExpanded-Bold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansExpanded-ExtraBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansExpanded-ExtraLight.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansExpanded-Light.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansExpanded-Medium.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansExpanded-Regular.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansExpanded-SemiBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansExpanded-Thin.ttf" }

    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Black.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Bold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-ExtraBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-ExtraLight.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Light.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Medium.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Regular.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-SemiBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiCondensed-Thin.ttf" }

    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Black.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Bold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-ExtraBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-ExtraLight.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Light.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Medium.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Regular.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-SemiBold.ttf" }
    FontLoader { source:"qrc:/assets/assets/encode-sans/EncodeSansSemiExpanded-Thin.ttf" }

    StackView {
        id: stackview
        anchors.fill: parent
        initialItem: application.getLoginPagePath()
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
