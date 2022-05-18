import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    id: root
    title: qsTr("Tabs")

    property int currentPage: 0

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: root.currentPage
        interactive: false

        Page1Form {

            Button {
                text: "Next"
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                onClicked: {
                    root.currentPage++
                }
            }

        }

        Page2Form {

            Button {
                text: "Prev"
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                onClicked: {
                    root.currentPage--
                }
            }

        }
    }
}
