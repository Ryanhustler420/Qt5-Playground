import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Some Example")

    BusyIndicator {
        id: busyIndicator
        x: 290
        y: 210
    }

    Dial {
        id: dial
        x: 37
        y: 27
    }

    Slider {
        id: slider
        x: 37
        y: 342
        value: 0.5
    }

    Button {
        id: button
        x: 471
        y: 99
        text: qsTr("Button")
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
