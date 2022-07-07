import QtQuick 2.12
import QtQuick.Controls 2.5

Label {
    property alias $root: root

    id: root
    font.pointSize: system.getH2FontSize()

    Connections {
        target: system
        onH2FontSizeChanged: {
            root.font.pointSize = Math.round(newSize)
        }
    }

}
