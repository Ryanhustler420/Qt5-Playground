import QtQuick 2.12
import QtQuick.Controls 2.5

import software.raisehand.dirhelper 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Tabs")

    DirHelper {
        id: dirHelper
        path: "file:///E:/SukriBirthday/IMG_5058.JPG"
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: 0

        Component.onCompleted: {
            var files = dirHelper.files

            for (var i = 0; i < files.length; i++)
            {
                console.log("Loading", files[i]);
                var component = Qt.createComponent("qrc:/ImagePage.qml");
                var page = component.createObject(swipeView, { "width" : 640, "height": 480 })
                page.source = files[i]
            }

        }

    }
}
