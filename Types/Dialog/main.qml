import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Dialog")

    Button {
        id: btn
        text: "Open Dialog"
        onClicked: {
            dialog.open()
        }
    }

    Dialog {
        id: dialog
        modal: true
        anchors.centerIn: parent
        title: "End User Licence Agreement"
        closePolicy: Dialog.CloseOnEscape | Dialog.CloseOnPressOutside
        standardButtons: Dialog.Ok | Dialog.Cancel

        width: parent.width / 3
        height: parent.height / 2

        Column {
            ScrollView {
                clip: true

                Text {
                    id: name
                    clip: true
                    width: dialog.width - 20
                    height: dialog.height - 50
                    wrapMode: Text.WordWrap
                    text: qsTr("<b>Lorem Ipsum</b> is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.  is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum")
                }

            }

            CheckBox {
                text: "I am accepting EULA"
            }

        }


        onAccepted: console.log("Ok clicked")
        onRejected: console.log("Cancel clicked")
    }

}
