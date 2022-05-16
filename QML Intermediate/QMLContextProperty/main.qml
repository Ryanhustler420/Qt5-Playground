import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Call C++ From QML")

    Column {
        spacing: 10
        Button {
            text: "Call C++ Method"
            onClicked: {
                $Worker.regularMethod()
                $Worker.cppSlot()
            }
        }
        Rectangle {
            width: textToShowId.implicitWidth + 20
            height: 50
            color: "beige"
            Text {
                id: textToShowId
                text: $Worker.regularMethodWithReturn("Gaurav", 25)
            }
        }
    }

    Other {
        //
    }

}
