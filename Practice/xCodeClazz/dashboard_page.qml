import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5

import com.xcodeclazz.dashboardcontroller 1.0
import "qrc:/js/ComponentGenerator.js" as ComponentGenerator

Page {
    id: root
    anchors.fill: parent
    title: qsTr("xCodeClazz")

    // these signals are being used in this page
    signal openCountState(string name, string count);
    onOpenCountState: { dashboard_controller.openCountState(name, count) }

    // life cycle of this class are being used here in this page
    Component.onCompleted: {
    }

    Row {
        anchors.fill: parent
        height: root.height
        width: root.width
        spacing: 25

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
                        console.log(modelData.name)
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
                visible: true
                anchors.fill: parent
                height: parent.height
                width: parent.width

                Column {
                    clip: true
                    id: right_col
                    width: parent.width
                    spacing: 20

                    /*************************************************/
                    /*************************************************/

                    Label {
                        width: parent.width
                        text: "Status"
                        font.bold: true
                        font.pointSize: 25
                    }

                    Text {
                        width: parent.width
                        font.pointSize: 12
                        wrapMode: Text.WordWrap
                        text: "You can see the status of your current condition of your site down below."
                    }

                    Flow {
                        id: overall_status
                        width: parent.width
                        spacing: 15

                        Component.onCompleted: {
                            var list = [
                                        { name: "Courses", count: "5" },
                                        { name: "Students", count: "15" },
                                        { name: "Callbacks", count: "32" },
                                    ]
                            for(var i =0; i< list.length; i++) {
                                ComponentGenerator.createCountState(i, list[i], overall_status);
                            }
                        }

                    }

                    /*************************************************/
                    /*************************************************/

                    Label {
                        width: parent.width
                        text: "Payments"
                        font.bold: true
                        font.pointSize: 25
                    }

                    Text {
                        width: parent.width
                        font.pointSize: 12
                        wrapMode: Text.WordWrap
                        text: "You can see the recent payment done by your student(s)"
                    }

                    Flow {
                        id: latest_payment_status
                        width: parent.width
                        spacing: 15

                        Component.onCompleted: {
                            var list = [
                                        { name: "Deepika", count: "3000/-" },
                                        { name: "Subham", count: "2950/-" },
                                        { name: "Anjali", count: "3000/-" },
                                    ]
                            for(var i =0; i< list.length; i++) {
                                ComponentGenerator.createCountState(i, list[i], latest_payment_status);
                            }
                        }

                    }

                    /*************************************************/
                    /*************************************************/

                }
            }
        }
    }

    DashboardPageController {
        id: dashboard_controller
    }

    //    Popup {
    //        id: loading
    //        width: parent.width
    //        height: parent.height
    //        anchors.centerIn: parent
    //        focus: true
    //        closePolicy: Popup.NoAutoClose

    //        BusyIndicator {
    //            id: bi_loading
    //            running: true
    //            anchors.centerIn: parent
    //        }

    //        Text {
    //            anchors.top: bi_loading.bottom
    //            text: qsTr("Loading\u2026")
    //            font.pointSize: 15
    //            anchors.horizontalCenter: parent.horizontalCenter
    //        }

    //        Component.onCompleted: {
    //            loading.open()
    //        }

    //    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:2}D{i:12}
}
##^##*/
