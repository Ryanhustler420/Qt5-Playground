import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // This is a comment!!!

    /*
        Makes life super easy
        This is multiline comment
    */

    Image {
        id: myimage
//        width: 250
//        height: 250
        source: "file:E:/SukriBirthday/IMG_5057.jpg"
        anchors.centerIn: parent
    }
}
