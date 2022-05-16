import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Label {
        id: label
        x: 59
        y: 77
        width: 93
        height: 14
        text: qsTr("This is simple label")
    }

    Label {
        id: label1
        x: 59
        y: 104
        width: 317
        height: 18
        color: "#1c6ab8"
        text: qsTr("This is the longest label i have ever seen in my life")
        wrapMode: Text.Wrap
        styleColor: "#ff0000"
    }

    Label {
        id: label2
        x: 59
        y: 32
        text: qsTr("<font color='gray'><b>&lt;- Back</b></font>")
    }
}
