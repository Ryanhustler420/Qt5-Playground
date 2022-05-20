import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Drawer")

    Drawer {
        id: drawer
        width: .3 * parent.width
        height: parent.height

        ListView {
            id: list
            anchors.fill: parent
            width: drawer.width
            model: [{ name: "Course" }, { name: "Students" }, { name: "Request Callbacks" }]
            delegate: ItemDelegate {
                width: parent.width
                height: 40
                Label {
                    padding: 10
                    font.pointSize: 10
                    text: modelData.name
                    anchors.verticalCenter: parent.verticalCenter
                }
                onClicked: {
                    console.log(modelData.name)
                    drawer.close()
                }
            }
        }

    }

    Button {
        text: "Drawer"
        onClicked: {
            drawer.open()
        }
    }

}
