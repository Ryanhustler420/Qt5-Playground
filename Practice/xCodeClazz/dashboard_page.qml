import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import QtQuick.Controls.Material 2.3

import com.xcodeclazz.dashboardcontroller 1.0
import "qrc:/js/ComponentGenerator.js" as ComponentGenerator

Page {
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true
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
            width: 200
            height: root.height

            ListView {
                id: list_options
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: parent.width
                model: [{ name: "Courses" }, { name: "Students" }, { name: "Callback Requests" }, { name: "Logout" }]
                delegate: ItemDelegate {
                    text: modelData.name
                    width: parent.width
                    onClicked: {
                        if (modelData.name === "Courses") {
                            application.gotoPage(application.getCoursesPagePath())
                        } else if (modelData.name === "Students") {
                            application.gotoPage(application.getStudentsPagePath())
                        } else if (modelData.name === "Callback Requests") {
                            application.gotoPage(application.getRequestCallbacksPagePath())
                        } else if (modelData.name === "Logout") {
                            application.replacePage(application.getLoginPagePath())
                        }
                    }
                }
            }
        }

        ColumnLayout {
            clip: true
            x: 200
            width: root.width - (200)
            height: root.height
            onWidthChanged: {
                right_col.width = width
            }

            ScrollView {
                padding: 10
                visible: true
                Layout.fillHeight: true
                Layout.fillWidth: true
                height: parent.height
                width: parent.width

                Column {
                    clip: true
                    id: right_col
                    width: parent.width
                    spacing: 15

                    /*************************************************/
                    /*************************************************/

                    Label {
                        width: parent.width
                        text: "Status"
                        font.bold: true
                        font.pointSize: 25
                    }

                    Label {
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
                                        { name: "Callbacks", count: "32" }
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

                    Label {
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
                                        { name: "Deepika", count: "3000" },
                                        { name: "Subham", count: "2950" },
                                        { name: "Anjali", count: "3000" },
                                    ]
                            for(var i =0; i< list.length; i++) {
                                ComponentGenerator.createCountState(i, list[i], latest_payment_status);
                            }
                        }

                    }

                    /*************************************************/
                    /*************************************************/

                    Label {
                        width: parent.width
                        text: "Course Progress"
                        font.bold: true
                        font.pointSize: 25
                    }

                    Label {
                        width: parent.width
                        font.pointSize: 12
                        wrapMode: Text.WordWrap
                        text: "You can see the current progress of respective course(s)"
                    }

                    Row {
                        width: parent.width
                        spacing: 10

                        Label {
                            Layout.alignment: Qt.AlignVCenter
                            text: "C++"
                            font.bold: true
                            font.pointSize: 10
                        }

                        ProgressBar {
                            height: parent.height
                            Layout.alignment: Qt.AlignVCenter
                            value: 0.6
                        }

                    }

                    Row {
                        width: parent.width
                        spacing: 10

                        Label {
                            Layout.alignment: Qt.AlignVCenter
                            text: "Python"
                            font.bold: true
                            font.pointSize: 10
                        }

                        ProgressBar {
                            height: parent.height
                            Layout.alignment: Qt.AlignVCenter
                            value: 0.3
                        }

                    }

                    Row {
                        width: parent.width
                        spacing: 10

                        Label {
                            Layout.alignment: Qt.AlignVCenter
                            text: "Java"
                            font.bold: true
                            font.pointSize: 10
                        }

                        ProgressBar {
                            height: parent.height
                            Layout.alignment: Qt.AlignVCenter
                            value: 0.9
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
    //            antialiasing: true
    //            anchors.centerIn: parent
    //        }

    //        Label {
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
