import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Call JS from C++")

    // NOTE:: function need to be on the root level in our this application example

    // this "qmlJSFunction" name should match on the c++ side
    function qmlJSFunction(parem) {
        console.log("QML Talking, C++ called me with parameter: " + parem + " returning back");
        return "This is QML, over to you c++. Thanks for the call";
    }

    Button {
        id: mButton
        text: "Call QML function from c++"
        onClicked: {
            QmlJSCaller.cppMethod("QML Calling...");
        }
    }

}
