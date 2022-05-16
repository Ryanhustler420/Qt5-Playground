import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Scroll")

    Component {
        id: delegate

        Item {
            id: item
            width: 200
            height: 50
            Column {
                anchors.fill: parent
                spacing: 5
                padding: 10

                Label {
                    text: name
                    font.bold: true
                }
                Label {
                    text: number
                }
            }
        }
    }

    // Database
    ListModel {
        id: model
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Gaurav Gupta"
            number: "9835718631"
        }
        ListElement {
            name: "Saurav Gupta"
            number: "9835718631"
        }
    }

    ScrollView {
        anchors.fill: parent

        ListView {
            id: listView
            width: parent.width
            model: model
            delegate: delegate
        }
    }
}
