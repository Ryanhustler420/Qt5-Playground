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
                create_new_student_form.open()
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
                if ((listScroll.position + listScroll.size) == 1) {
                    console.log("fetch more data")
                    const oldPos = listScroll.position
                    const oldSize = listScroll.size
                    listScroll.position = oldPos - listScroll.position
                    page_controller.listViewReachedBottom({});
                }
            }
            ScrollBar.vertical: ScrollBar {
                id: listScroll
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
            ScrollBar.vertical: ScrollBar {
                id: scroll_handle
                height: 0
                onPositionChanged: {
                    if (scroll_handle.position + scroll_handle.size == 1) {
                        page_controller.scrollViewReachedBottom({});
                    }
                }
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
        width: 420
        modal: true
        focus: true
        id: create_new_student_form
        anchors.centerIn: parent
        closePolicy: Popup.NoAutoClose

        ScrollView {
            clip: true
            visible: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            height: parent.height
            width: parent.width
            ScrollBar.vertical: ScrollBar {
                height: 0
            }

            Column {
                width: parent.width
                spacing: 5

                Row {
                    width: parent.width

                    Label {
                        font.bold: true
                        font.pointSize: 20
                        text: "Create Student"
                        width: parent.width * .9
                    }

                    Label {
                        text: "X"
                        font.bold: true
                        font.pointSize: 20
                        width: parent.width * .1

                        MouseArea {
                            cursorShape: Qt.PointingHandCursor
                            anchors.fill: parent
                            onClicked: {
                                create_new_student_form.close()
                            }
                        }

                    }

                }

                TextField {
                    id: new_student_student_tf
                    placeholderText: "School"
                    width: parent.width
                }

                TextField {
                    id: new_student_name_tf
                    placeholderText: "Name"
                    width: parent.width
                }

                TextField {
                    id: new_student_avatar_tf
                    placeholderText: "Avatar Url"
                    width: parent.width
                }

                TextField {
                    id: new_student_age_tf
                    placeholderText: "Age"
                    width: parent.width
                }

                TextField {
                    id: new_student_clazz_tf
                    placeholderText: "Clazz"
                    width: parent.width
                }

                ComboBox {
                    id: new_student_course_id_cb
                    width: parent.width
                    model: [ "C++ Course For Biggener", "Java Code", "Python Core" ]
                }

                Row {
                    width: parent.width
                    spacing: 5

                    TextField {
                        id: new_student_time_start_tf
                        width: parent.width * .5
                        placeholderText: "Session Starts"
                    }

                    TextField {
                        id: new_student_time_ends_tf
                        width: parent.width * .5
                        placeholderText: "Session Ends"
                    }

                }

                Row {
                    width: parent.width
                    spacing: 5
                    CheckBox {id: new_student_work_week_sunday_ckb; text: "S"}
                    CheckBox {id: new_student_work_week_monday_ckb; text: "M"}
                    CheckBox {id: new_student_work_week_tuesday_ckb; text: "T"}
                    CheckBox {id: new_student_work_week_wednesday_ckb; text: "W"}
                    CheckBox {id: new_student_work_week_thursday_ckb; text: "T"}
                    CheckBox {id: new_student_work_week_friday_ckb; text: "F"}
                    CheckBox {id: new_student_work_week_saturday_ckb; text: "S" }
                }

                TextField {
                    id: new_student_phone_numbers_tf
                    placeholderText: "Phone Numbers, "
                    width: parent.width
                }

                TextField {
                    id: new_student_joinDate_tf
                    placeholderText: "Joining From"
                    width: parent.width
                }

                Row {
                    width: parent.width
                    spacing: 5

                    TextField {
                        id: new_student_fee_amount_tf
                        width: parent.width * .5
                        placeholderText: "Amount"
                    }

                    TextField {
                        id: new_student_fee_per_tf
                        width: parent.width * .5
                        placeholderText: "Per"
                    }

                }

                TextField {
                    id: new_student_batchNumber_tf
                    placeholderText: "Batch Number"
                    width: parent.width
                }

                TextField {
                    id: new_student_email_tf
                    placeholderText: "Email Address"
                    width: parent.width
                }

                Button {
                    text: "Create"
                    width: parent.width
                    onClicked: {
                        if (isCreateNewStudentFormValid()) {
                            page_controller.createNewStudent(getCreateNewStudentFormData());
                            resetCreateNewStudentForm();
                            create_new_student_form.close()
                        }
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
        onListViewReached: {}
        onScrollViewReached: {}
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
        return search_field.text.length === 0;
    }

    function add_to_model(dataArray, model_id) {
        for(let i = 0; i < dataArray.length; i++) {
            model_id.append(JSON.parse(JSON.stringify(dataArray[i])))
        }
    }

    function resetCreateNewStudentForm() {
        new_student_name_tf.text
                = "";
    }

    function getCreateNewStudentFormData() {
        return {
            'name': new_student_name_tf.text,
        }
    }

    function isCreateNewStudentFormValid() {
        return true;
    }

}
