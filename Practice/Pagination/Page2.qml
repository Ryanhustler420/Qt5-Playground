import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import "component_generator.js" as ComponentGenerator

Page {
    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

    title: qsTr("Scroller View")

    ScrollView {
        padding: 10
        visible: true
        Layout.fillHeight: true
        Layout.fillWidth: true
        height: parent.height
        width: parent.width
        ScrollBar.vertical: ScrollBar {

            id: scroll_handle
            onPositionChanged: {
                if (scroll_handle.position + scroll_handle.size == 1) {
                    var list = [0, 1, 2, 3, 4, 5, 6]
                    for(var i =0; i< list.length; i++) {
                        ComponentGenerator.card(i, grid);
                    }
                }
            }

        }

        Flow {
            id: grid
            width: parent.width
            spacing: 15

            Component.onCompleted: {
                var list = [0, 1, 2, 3, 4, 5, 6]
                for(var i =0; i< list.length; i++) {
                    ComponentGenerator.card(i, grid);
                }
            }

        }

    }

}
