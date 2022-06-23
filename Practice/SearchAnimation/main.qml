import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Search Animation")

    ColumnLayout {
        width: parent.width
        height: parent.height
        Layout.fillWidth: true
        Layout.fillHeight: true

        Rectangle {
            id: search_rect
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height * .3

            property bool flip: false

            TextField {
                id: textField
                width: 400
                anchors.bottom: parent.bottom
                placeholderText: "User email address..."
                anchors.bottomMargin: 10
                anchors.horizontalCenter: parent.horizontalCenter
                onFocusChanged: {
                    if(search_rect.flip) {
                        animationSearching.start()
                    } else {
                        animationSearchBegin.start()
                    }
                    search_rect.flip = !search_rect.flip
                }
            }

        }

        Action {
            shortcut: "return"
            onTriggered: {
                textField.focusChanged(false)
            }
        }

        Rectangle {
            clip: true
            id: result_rect
            border.color: "#ffffff"
            Layout.margins: 10
            Layout.fillHeight: true
            Layout.fillWidth: true

            Flow {
                id: flow1
                anchors.fill: parent
                spacing: 10

                Rectangle {
                    id: rectangle
                    width: 200
                    height: 200
                    color: "#cb1313"
                }

                Rectangle {
                    id: rectangle1
                    width: 200
                    height: 200
                    color: "#cb1313"
                }

                Rectangle {
                    id: rectangle2
                    width: 200
                    height: 200
                    color: "#cb1313"
                }

                Rectangle {
                    id: rectangle3
                    width: 200
                    height: 200
                    color: "#cb1313"
                }

                Rectangle {
                    id: rectangle4
                    width: 200
                    height: 200
                    color: "#cb1313"
                }

                Rectangle {
                    id: rectangle5
                    width: 200
                    height: 200
                    color: "#cb1313"
                }

                Rectangle {
                    id: rectangle6
                    width: 200
                    height: 200
                    color: "#cb1313"
                }

                Rectangle {
                    id: rectangle7
                    width: 200
                    height: 200
                    color: "#cb1313"
                }

                Rectangle {
                    id: rectangle8
                    width: 200
                    height: 200
                    color: "#cb1313"
                }
            }
        }

        PropertyAnimation {
            id: animationSearchBegin
            target: search_rect
            property: "Layout.preferredHeight"
            to: root.height * .5
            duration: 500 // ms, effect the speed
        }

        PropertyAnimation {
            id: animationSearching
            target: search_rect
            property: "Layout.preferredHeight"
            to: root.height * .3
            duration: 500 // ms, effect the speed
        }

    }

}
