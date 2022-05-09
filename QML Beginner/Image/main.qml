import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // java script???
    property int middle: height / 2

    Image {
        id: localImage
        source: "qrc:/images/IMG_5060.JPG"

        width: 100
        // height: 100
        fillMode: Image.PreserveAspectFit

        x: 300
        y: middle - 100
    }

    Image {
        id: remoteImage
        source: "https://via.placeholder.com/100x100"

        width: 100
        // height: 100
        fillMode: Image.PreserveAspectFit

        x: 100
        y: middle

        onProgressChanged: console.log(remoteImage.progress)
        onStateChanged: if (remoteImage.status == Image.Ready) console.log("Remote image was loaded");
    }

}
