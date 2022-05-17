import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Sequence Demo")

    Button {
        id: mButton1
        text: "Send to c++"
        onClicked: {
            var array = ['Apple', 'Banana', 'Avocado', 'Pear', 'Orange'];
            CppClass.qmlArrayToCpp(array);
        }
    }

    Button {
        id: mButton2
        text: "Read from c++"
        anchors.top: mButton1.bottom
        onClicked: {
            var array = CppClass.retrieveStrings();
            print(array.length);

            array.forEach(function (element) {
                console.log(element)
            });

        }
    }

}
