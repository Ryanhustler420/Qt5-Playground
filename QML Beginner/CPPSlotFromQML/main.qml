import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

// Test class, it's here from Window to all the way down childrend object

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column {
        id: column
        width: 200
        height: 200
        anchors.centerIn: parent
        spacing: 25

        Label {
            id: label
            text: qsTr("Call a C++ Slot")
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            id: button
            text: qsTr("Click Me")
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: {
                // call the slot
                anything.bark();

                // Can not call a non-slot - must be a property
                var num = anything.number();
                print(num);
                // TypeError: Property 'number' of object Test(0x71fcf0) is not a function
            }
        }

    }

}
