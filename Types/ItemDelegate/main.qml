import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("ItemDelegate")

    ListView {
        width: parent.width
        height: parent.height

        model: Qt.fontFamilies()

        delegate: ItemDelegate {
            text: modelData
            width: parent.width
            onClicked: {
                console.log(modelData, index)
            }
        }

        ScrollIndicator.vertical: ScrollIndicator {

        }

    }

}
