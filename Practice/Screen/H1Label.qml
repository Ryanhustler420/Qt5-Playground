import QtQuick 2.12
import QtQuick.Controls 2.5

Label {
    property alias $root: root

    id: root
    font.pointSize: system.getH1FontSize()

    Connections {
        target: system
        onH1FontSizeChanged: { 
            root.font.pointSize = Math.round(newSize)
        }
    }

}
