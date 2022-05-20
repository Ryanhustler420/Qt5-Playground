import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import com.xcodeclazz.dashboardcontroller 1.0

Page {
    id: root
    anchors.fill: parent
    title: qsTr("xCodeClazz")

    Component.onCompleted: {

    }

    Row {
        anchors.fill: parent
        height: root.height
        width: root.width

        ColumnLayout {
            clip: true
            width: root.width * .3
            height: root.height

            ListView {
                id: list_options
                anchors.fill: parent
                width: parent.width
                model: [{ name: "Courses" }, { name: "Students" }, { name: "Callback Requests" }]
                delegate: ItemDelegate {
                    text: modelData.name
                    width: parent.width
                    onClicked: {

                    }
                }
            }

        }

        ColumnLayout {
            clip: true
            x: root.width * .3
            width: root.width - (root.width * .3)
            height: root.height
            onWidthChanged: {
                right_col.width = width
            }

            ScrollView {
                anchors.fill: parent
                height: parent.height
                width: parent.width

                Column {
                    clip: true
                    id: right_col
                    width: parent.width
                    spacing: 10

                    Label {
                        width: parent.width
                        text: "Status"
                        font.bold: true
                        font.pointSize: 25
                    }

                    Text {
                        width: parent.width
                        font.pointSize: 12
                        wrapMode: Text.WrapAnywhere
                        text: "You can see the status of your current condition of your site down below."
                    }

                    Flow {
                        id: flow
                        width: parent.width
                        spacing: 10

                        Component.onCompleted: {
                            console.log("hello")

                            for(var i =0; i< 10; i++) {
                                Qt.createQmlObject(`import QtQuick 2.0; import QtQuick.Controls 2.3; Rectangle { id: rect${i}; width:200; height:200; border.color: "black"; }`, flow, "KuchV");
                            }
                        }

                    }

                }


            }
        }
    }

    DashboardPageController {
        id: dashboard_controller
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:2}D{i:12}
}
##^##*/
