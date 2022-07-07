import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls 1.4

ApplicationWindow {
    id: window
    visible: true
    width: 300; height: 500

    readonly property int responsiveWidth: 500

    SwipeView  {
        id: swipeView
        currentIndex: 1
        anchors.fill: parent
        states: [
            State {
                when: window.width >= responsiveWidth
                ParentChange { target: contacts; parent: contactsContainer; }
                ParentChange { target: chat; parent: chatContainer; }
                PropertyChanges { target: indicator; visible: hide }
            }
        ]
        Item {
            Rectangle {
                id: contacts
                anchors.fill: parent
                color: "lightblue"
            }
        }
        Item {
            Rectangle{
                id: chat
                anchors.fill: parent
                color: "lightgray"
            }
        }
    }

    PageIndicator {
        id: indicator
        count: swipeView.count
        currentIndex: swipeView.currentIndex
        anchors.bottom: swipeView.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: swipeView.horizontalCenter
    }

    Row {
        id: splitView
        anchors.fill: parent
        Item {
            id: contactsContainer
            width: parent.width * .2; height: parent.height
        }
        Item {
            id: chatContainer
            width: parent.width * .8; height: parent.height
        }
    }
}
