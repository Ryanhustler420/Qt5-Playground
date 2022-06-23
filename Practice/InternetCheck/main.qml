import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

import com.app.inetwork 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Internet Check")

    Button {
        text: "Fetch"
        anchors.centerIn: parent
        onClicked: {
            page_controller.fetch();
        }
    }

    Popup {
        width: 400
        height: 400
        modal: true
        focus: true
        id: message
        anchors.centerIn: parent
        closePolicy: Popup.CloseOnPressOutside | Popup.CloseOnEscape

        Label {
            id: message_lbl
            anchors.centerIn: parent
            text: "Something..."
        }
    }

    Popup {
        width: 400
        height: 400
        modal: true
        focus: true
        id: fetched
        anchors.centerIn: parent
        closePolicy: Popup.CloseOnPressOutside | Popup.CloseOnEscape

        ListModel { id: modelI }
        ListView {
            clip: true
            width: parent.width
            height: parent.height
            model: modelI
            delegate: Row {
                padding: 10
                spacing: 10
                width: parent.width

                Column {
                    width: parent.width
                    spacing: 5

                    Label {
                        text: `${title}`
                        font.bold: true
                        font.pointSize: 10
                        width: parent.width
                        wrapMode: Text.WordWrap
                    }

                    Label {
                        text: `${body}`
                        font.pointSize: 6
                        width: parent.width
                        wrapMode: Text.WordWrap
                    }

                }

            }
        }
    }

    Component.onCompleted: {
        page_controller.load();
    }

    INetwork {
        id: page_controller
        onFetched: {
            modelI.clear()
            const array = JSON.parse(data);
            for(let i = 0; i < array.length; i++)
            {
                modelI.append(array[i])
            }
            fetched.open()
        }
        onLoaded: {
            message_lbl.text = v;
            message.open()
        }
    }

}
