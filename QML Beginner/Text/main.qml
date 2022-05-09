import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: myText
        // text: qsTr("Raisehand")
        text: qsTr("<html><b>Hello</b><i><font color='green'>World</font></i></html>
<br>
<font color='#C0C0C0'>This is a test</font>
<br>
<a href='https://www.raisehand.software'>mysite</a>
")
        anchors.centerIn: parent
        font.pointSize: 35
        font.bold: true // might not work
        font.italic: false // might not work
        color: "red"
        linkColor: "blue" // default blue

        // html can overrid the styling if you used style in html

        onLinkHovered: {
            console.log("Hovering: " + link)
            if (link) {
                myText.font.bold = true;
            } else {
                myText.font.bold = false;
            }
        }

        onLinkActivated: {
            Qt.openUrlExternally(link)
        }
    }

}
