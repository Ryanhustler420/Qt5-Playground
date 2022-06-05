import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import com.xcodeclazz.allstudentspagecontroller 1.0

Page {
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true
    title: qsTr("xCodeClazz")

    FontLoader { id: mainFont; source: assets.getEncodeSans_ExtraLight() }

    header: Item {
        height: 70
        width: parent.width

        Label {
            id: title
            padding: 10
            font.bold: true
            font.pointSize: 30
            text: qsTr("Students")
            anchors.left: parent.left
        }

        Button {
            id: create_student_btn
            text: "New Student"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 10
            onClicked: {
                console.log("Implement Form")
            }
        }

    }

    Label {
        id: nothing_found_label
        property string weight
        text: "No Student Found"
        padding: 10
        visible: students_listview.count == 0
        font {
            styleName: weight
            family: mainFont.name
            pointSize: 25
        }
    }

    Row {
        clip: true
        width: parent.width
        height: parent.height
        onWidthChanged: {
            width: parent.width
            height: parent.height
        }

        ListModel { id: students_model }
        ListView {
            id: students_listview
            clip: true
            leftMargin: 10
            topMargin: 10
            spacing: 10
            height: parent.height
            width: parent.width * (isPreviewStudent() ? 0.4 : 1.0)
            highlightFollowsCurrentItem: true
            onWidthChanged: {
                height: parent.height
                width: parent.width * (isPreviewStudent() ? 0.4 : 1.0)
            }
            model: students_model
            onMovementEnded: { }
            onMovementStarted: { }
            onContentYChanged: {
                if ((taskScroll.position + taskScroll.size) == 1) {
                    console.log("fetch more data")
                    const oldPos = taskScroll.position
                    const oldSize = taskScroll.size
                    taskScroll.position = oldPos - taskScroll.position
                }
            }
            ScrollBar.vertical: ScrollBar {
                id: taskScroll
                height: 0
            }
            delegate: Component {
                Item {
                    width: parent.width
                    height: 80

                    Column {
                        width: parent.width

                        Row {
                            width: parent.width
                            spacing: 5

                            Label {
                                color: "grey"
                                text: `${school}`
                                font.bold: true
                                font.pointSize: 10
                            }

                            Label {
                                color: "grey"
                                text: `• ${std}`
                                font.bold: true
                                font.pointSize: 10
                            }

                        }

                        Row {
                            width: parent.width

                            Label {
                                text: `${name}`
                                font.pointSize: 20
                                font.bold: false
                            }

                        }

                    }

                }
            }
        }

        ScrollView {
            clip: true
            visible: (students_listview.count > 0 && isPreviewStudent())
            Layout.fillHeight: true
            Layout.fillWidth: true
            width: parent.width * 0.6
            height: parent.height
            onWidthChanged: {
                width: parent.width * 0.6
                height: parent.height
            }

            Column {
                width: parent.width
                onWidthChanged: {
                    width: parent.width
                }
                spacing: 20

                Column {
                    width: parent.width
                    onWidthChanged: {
                        width = parent.width
                    }
                    spacing: 5

                    Label {
                        width: parent.width
                        font.pointSize: 25
                        wrapMode: Text.WordWrap
                        text: "Gaurav Kumar Gupta"
                    }

                    Label {
                        color: "gray"
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        text: "Joined @ 12-May-2022"
                    }

                }

                Column {
                    width: parent.width
                    onWidthChanged: {
                        width = parent.width
                    }
                    spacing: 5

                    Label {
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        text: "School/College"
                    }

                    Label {
                        color: "gray"
                        width: parent.width
                        font.pointSize: 10
                        wrapMode: Text.WordWrap
                        text: "KPS Gamharia"
                    }

                }

                Column {
                    width: parent.width
                    onWidthChanged: {
                        width = parent.width
                    }
                    spacing: 5

                    Label {
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        text: "Class"
                    }

                    Label {
                        color: "gray"
                        width: parent.width
                        font.pointSize: 10
                        wrapMode: Text.WordWrap
                        text: "9 (A)"
                    }

                }

                Column {
                    width: parent.width
                    onWidthChanged: {
                        width = parent.width
                    }
                    spacing: 5

                    Label {
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        text: "Age"
                    }

                    Label {
                        color: "gray"
                        width: parent.width
                        font.pointSize: 10
                        wrapMode: Text.WordWrap
                        text: "15"
                    }

                }

                Column {
                    width: parent.width
                    onWidthChanged: {
                        width = parent.width
                    }
                    spacing: 5

                    Label {
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        text: "Courses"
                    }

                    Row {
                        width: parent.width
                        spacing: 20

                        Image {
                            width: 30
                            height: 30
                            fillMode: Image.PreserveAspectFit
                            source: "http://xcodeclazz.com/assets/java-icon.svg"
                        }

                        Image {
                            width: 30
                            height: 30
                            fillMode: Image.PreserveAspectFit
                            source: "http://xcodeclazz.com/assets/python-icon.svg"
                        }

                    }

                }

                // Fees
                // - [Done] 1st Payment of ${course_id}

                Column {
                    width: parent.width
                    onWidthChanged: {
                        width = parent.width
                    }
                    spacing: 5

                    Label {
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        text: "Time Slot"
                    }

                    Label {
                        color: "gray"
                        width: parent.width
                        font.pointSize: 10
                        wrapMode: Text.WordWrap
                        text: "10am - 11am (MWF)"
                    }

                }

                Column {
                    width: parent.width
                    onWidthChanged: {
                        width = parent.width
                    }
                    spacing: 5

                    Label {
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        text: "Phone"
                    }

                    Label {
                        color: "gray"
                        width: parent.width
                        font.pointSize: 10
                        wrapMode: Text.WordWrap
                        text: "xxxxxxxxx"
                    }

                }

                Column {
                    width: parent.width
                    onWidthChanged: {
                        width = parent.width
                    }
                    spacing: 5

                    Label {
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        text: "Email Address"
                    }

                    Label {
                        color: "gray"
                        width: parent.width
                        font.pointSize: 10
                        wrapMode: Text.WordWrap
                        text: "example@domain.com"
                    }

                }

                Column {
                    width: parent.width
                    onWidthChanged: {
                        width = parent.width
                    }
                    spacing: 5

                    Label {
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        text: "Batch Number"
                    }

                    Label {
                        color: "gray"
                        width: parent.width
                        font.pointSize: 10
                        wrapMode: Text.WordWrap
                        text: "3"
                    }

                }
            }
        }

    }

    Popup {
        id: popup
        modal: true
        focus: true
        anchors.centerIn: parent
        closePolicy: Popup.NoAutoClose

        Label {
            anchors.centerIn: parent
            text: "Loading\u2026"
            font.pointSize: 12
        }
    }

    AllStudentsPageController {
        id: page_controller
        onShowLoading: {
            if (b) {
                popup.open()
            } else {
                popup.close()
            }
        }
        onStudentsLoaded: {
            add_to_model(students, students_model);
        }
    }

    Component.onCompleted: {
        page_controller.loadStudents();
    }

    function isPreviewStudent() {
        return true;
    }

    function searchFieldEmpty() {
        return search_field.text.length == 0;
    }

    function add_to_model(dataArray, model_id) {
        for(let i = 0; i < dataArray.length; i++) {
            model_id.append(JSON.parse(JSON.stringify(dataArray[i])))
        }
    }

}
