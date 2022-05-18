import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.4

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("REst Client")

    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        ListView {
            id: mListView
            model: 30
            delegate: Rectangle {

                width: parent.width
                height: textId.implicitHeight + 30
                color: "beige"
                border.color: "yellowgreen"
                radius: 5

                Text {
                    width: parent.width
                    height: parent.height
                    id: textId
                    anchors.centerIn: parent
                    text: modelData
                    font.pointSize: 13
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignVCenter
                }
            }

            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        Button {
            id: mButton
            text: "Fetch"
            Layout.fillWidth: true
            onClicked: {
                Wrapper.fetchPosts(5);
            }
        }
    }

}
