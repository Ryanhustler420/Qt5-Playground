import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import com.test.page1controller 1.0

Page {
    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter

    title: qsTr("List View")

    ScrollView {
        anchors.fill: parent

        ListView {
            id: listView
            ScrollBar.vertical: ScrollBar {
                id: taskScroll
            }
            onMovementStarted: {

            }
            onMovementEnded: {

            }

            onContentYChanged: {
                console.log(taskScroll.position, taskScroll.size)
                if ((taskScroll.position + taskScroll.size) == 1) {
                    console.log("fetch more data")
                    const oldPos = taskScroll.position
                    const oldSize = taskScroll.size
                    listView.model = listView.model + 10
                    taskScroll.position = oldPos - taskScroll.position
                }
            }
            width: parent.width
            model: 20
            delegate: ItemDelegate {
                text: "Item " + (index + 1)
                width: listView.width
            }
        }
    }

    Page1Controller {
        id: page_controller
    }
}
