import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Connections")

    Connections {
        target: CppSignalSender
        onCallQml: {
            console.log(parameter)
            mText.text = parameter
        }
        onCppTimer: {
            console.log(value);
            mRectText.text = value;
        }
    }

    Column {

        Rectangle {
            width: 200
            height: 200
            color: "purple"
            radius: width

            Text {
                id: mRectText
                text: "0"
                anchors.centerIn: parent
                color: "white"
                font.pointSize: 30
            }
        }

        Button {
            text: "Call C++ Method"
            onClicked: {
                CppSignalSender.cppSlot()
            }
        }

        Text {
            id: mText
            text: "Default"
        }

    }

}
