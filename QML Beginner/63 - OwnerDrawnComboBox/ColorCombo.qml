import QtQuick 2.0
import QtQuick.Controls 2.3

// Owner Draw a Component

ComboBox {
    id: root
    model: ["red", "green", "blue", "yellow", "orange"]

    delegate: ItemDelegate {
        width: root.width
        highlighted: highlightedIndex === index

        contentItem: Row {
            spacing: 5
            width: root.width

            // Draw the color rectangle
            Rectangle {
                anchors.verticalCenter: parent.verticalCenter
                width: 10
                height: 10
                border.width: 1
                border.color: "black"
                color: modelData
            }

            // Add the text
            Text {
                id: name
                text: modelData
                color: "black"
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
            }
        }

        background: Rectangle {
            width: root.width
            implicitHeight: 40
            implicitWidth: 100
            border.color: currentIndex === index ? "green" : "White"
            color: currentIndex === index ? "lightgreen" : "White"
        }

    }
}
