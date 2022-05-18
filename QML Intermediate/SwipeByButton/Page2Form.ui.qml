import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    header: Label {
        id: header
        text: qsTr("Stocks")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    ListView {
        id: listView
        width: parent.width
        height: parent.height - header.height
        model: [{
                "name": "Ramhes",
                "age": 52
            }, {
                "name": "Gaurav",
                "age": 23
            }]
        delegate: ItemDelegate {
            text: modelData.name
            width: parent.width
        }
    }
}
