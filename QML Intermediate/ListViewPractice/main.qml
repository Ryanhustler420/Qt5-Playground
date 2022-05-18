import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

import software.raisehand.server 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Server {
        id: myserver
        onResponse: {
            console.log(v.length);
            myModel.append({v: v[0]})
        }
    }

    ListModel {
        id: myModel
        ListElement {
            name: "Bill Smith"
            number: "555 3264"
        }
        ListElement {
            name: "John Brown"
            number: "555 8426"
        }
        ListElement {
            name: "Sam Wise"
            number: "555 0473"
        }
    }

    ListView {
        id: listView
        model: myModel
        height: parent.height - getBtn.height
        width: parent.width
        anchors.horizontalCenter: parent.horizontalCenter
        delegate: Rectangle{
            width: parent.width
            height: 50

            Text {
                width: parent.width
                height: parent.height
                id: s
                text: `${name} : ${number}`
            }

        }
    }

    Button {
        id: getBtn
        text: "Get"
        height: 50
        anchors.top: listView.bottom
        width: parent.width
        onClicked: {
            myserver.fetchData()
        }
    }

}
