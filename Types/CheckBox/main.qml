import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Checkbox")

    Grid {
        id: grid
        anchors.fill: parent
        spacing: 10
        columns: 3

        Rectangle {
            id: rectangle
            width: 200
            height: 200
            border.color: "red"

            Column {
                id: ex_one

                CheckBox {
                    text: "First"
                    checkState: Qt.Checked
                    nextCheckState: {
                        console.log(checked)
                    }
                    tristate: true
                }

                CheckBox {
                    text: "Second"
                    checkState: Qt.Checked
                    nextCheckState: {
                        console.log(checked)
                    }
                    tristate: false
                }

            }

        }

        Rectangle {
            id: rectangle1
            width: 200
            height: 200
            border.color: "green"

            Column {
                id: ex_two
                anchors.centerIn: parent

                CheckBox {
                    tristate: true
                    checkState: true ? Qt.Checked : false ? Qt.PartiallyChecked : Qt.Unchecked
                    nextCheckState: function() {
                        if (checkState === Qt.Checked) {
                            return Qt.Unchecked
                        } else {
                            return Qt.Checked
                        }
                    }
                }

            }

        }

        Rectangle {
            id: rectangle2
            width: 200
            height: 200
            border.color: "purple"

            ListView {
                id: auto_gen_list
                anchors.fill: parent

                model: ["Course", "Students", "Request"]
                delegate: Row {
                    spacing: 10
                    width: parent.width

                    Rectangle {
                        id: rect
                        border.color: "black"
                        width: parent.width
                        height: 40

                        Label {
                            anchors.centerIn: rect
                            text: modelData
                            font.bold: true
                        }

                        MouseArea {
                            anchors.fill: rect
                            onClicked: {
                                console.log(modelData)
                            }
                        }

                    }
                }

            }

        }

        Rectangle {
            id: rectangle3
            width: 200
            height: 200
            border.color: "blue"

            ListView {
                anchors.fill: parent

                model: ["Course", "Students", "Request"]
                delegate: CheckDelegate {
                    text: modelData
                    width: parent.width
                    font.bold: true
                }

            }

        }

        Rectangle {
            id: rectangle4
            width: 200
            height: 200
            border.color: "black"

            ListView {
                anchors.fill: parent

                model: [{ name: "Pepsi", id: 1 }, { name: "Cola", id: 2 }, { name: "Coke", id: 3 }]
                delegate: Button {
                    width: parent.width
                    text: modelData.name
                    onClicked: {
                        console.log(modelData.id)
                    }
                }

            }

        }

        Rectangle {
            id: rectangle5
            width: 200
            height: 200
            border.color: "orange"

            ListView {
                anchors.fill: parent

                model: [{ name: "Dick", id: 1 }, { name: "Pussy", id: 2 }, { name: "Tits", id: 3 }]
                delegate: Component {
                    Button {
                        width: parent.width
                        text: modelData.name
                        onClicked: {
                            console.log(modelData.id, modelData.name)
                        }
                    }

                }


            }

        }
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:1}
}
##^##*/
