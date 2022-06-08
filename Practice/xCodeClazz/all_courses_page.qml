import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import QtQuick.Controls.Material 2.3

import com.xcodeclazz.allcoursespagecontroller 1.0
import "qrc:/js/ComponentGenerator.js" as ComponentGenerator

Page {
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true
    title: qsTr("xCodeClazz")

    // properties
    property var courses_list: []
    property bool isPageOnFocus: false

    // listeners
    onFocusChanged: {
        isPageOnFocus = !isPageOnFocus;
        if (isPageOnFocus) {
            // courses_list[0].ref.destroy()
            // courses_list.shift()
        }
    }

    // Page Life Cycle
    Component.onCompleted: { page_controller.loadCourses() }

    // Controller
    AllCoursesPageController {
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
        onCourseDeleted: {
            const doc = JSON.parse(JSON.stringify(course));
            for(let i = 0; i < courses_list.length; i++) {
                if (courses_list[i]._id === doc._id) {
                    courses_list[i].ref.destroy();
                    courses_list.splice(i, 1);
                }
            }
            nothing_found_here_label.visible = courses_list.length == 0;
        }
        onCoursesLoaded: {
            for(var i =0; i< courses.length; i++) {
                const doc = JSON.parse(JSON.stringify(courses[i]));
                const ref = ComponentGenerator.createCourseCard(doc._id, doc, application.getSiteAssetsUrl(), coursesContainer);
                courses_list.push({_id: doc._id, ref});
            }
            nothing_found_here_label.visible = courses_list.length == 0;
        }
        onNewCourseCreated: {
            const doc = JSON.parse(JSON.stringify(course));
            const ref = ComponentGenerator.createCourseCard(doc._id, doc, application.getSiteAssetsUrl(), coursesContainer);
            courses_list.push({_id: doc._id, ref});
            nothing_found_here_label.visible = courses_list.length == 0;
        }
        onPassed: {}
    }

    // methods
    function resetCreateNewCourseForm() {
        new_course_has_active_cb.checked = false;

        new_course_space_left_sb.value
                = new_course_space_full_sb.value = 0;

        new_course_title_tf.text
                = new_course_subtitle_tf.text
                = new_course_duration_tf.text
                = new_course_thumbnail_tf.text
                = new_course_features_tf.text
                = new_course_price_tf.text
                = new_course_session_start_tf.text
                = new_course_session_ends_tf.text
                = "";
    }

    function getCreateNewCourseFormData() {
        return {
            'title': new_course_title_tf.text,
            'subtitle': new_course_subtitle_tf.text,
            'duration': new_course_duration_tf.text,
            'thumbnailUrl': new_course_thumbnail_tf.text,
            'price': new_course_price_tf.text,
            'hasActive': new_course_has_active_cb.checked,
            'spaceLeft': new_course_space_left_sb.value,
            'spaceFull': new_course_space_full_sb.value,
            'session': {
                'starts': new_course_session_start_tf.text,
                'ends': new_course_session_ends_tf.text,
            },
            'features': new_course_features_tf.text.split("|"),
        }
    }

    function isCreateNewCourseFormValid() {
        return true;
    }

    function openCourse(object) {
        // these functions are being used in this page
        page_controller.pass(JSON.stringify(object))
        application.gotoPage(application.getSingleCoursePagePath())
    }

    // user interface
    header: Item {
        height: 70
        width: parent.width

        Label {
            id: title
            padding: 10
            font.bold: true
            font.pointSize: 30
            text: qsTr("Courses")
            anchors.left: parent.left
        }

        Button {
            id: create_course_btn
            text: "Create New Course"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 10
            onClicked: {
                create_new_course_form.open()
            }
        }

    }

    ScrollView {
        clip: true
        height: parent.height
        anchors.fill: parent
        width: parent.width
        visible: true
        padding: 10
        onWidthChanged: {
            couses_list.width = width
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
            id: couses_list
            clip: true
            width: parent.width
            spacing: 20

            FontLoader { id: mainFont; source: assets.getEncodeSans_ExtraLight() }
            Label {
                width: parent.width
                font.pointSize: 12
                wrapMode: Text.WordWrap
                text: "Following are the courses you are providing to all of your bright student(s) "
            }

            Label {
                id: nothing_found_here_label
                property string weight
                text: "Nothing Found Here"
                visible: false
                font {
                    family: mainFont.name
                    styleName: weight
                    pointSize: 25
                }
            }

            Flow {
                id: coursesContainer
                width: parent.width
                spacing: 15
            }

        }
    }

    Popup {
        width: 350
        modal: true
        focus: true
        id: create_new_course_form
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
                        text: "Course Create"
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
                                create_new_course_form.close()
                            }
                        }

                    }

                }

                TextField {
                    id: new_course_title_tf
                    placeholderText: "Title"
                    width: parent.width
                }

                TextField {
                    id: new_course_subtitle_tf
                    placeholderText: "Subtitle"
                    width: parent.width
                }

                TextField {
                    id: new_course_duration_tf
                    placeholderText: "Duration 3 Months"
                    width: parent.width
                }

                TextField {
                    id: new_course_thumbnail_tf
                    placeholderText: "Thumbnail Slug /assts/img.png"
                    width: parent.width
                }

                TextField {
                    id: new_course_features_tf
                    placeholderText: "Features | One | By | One"
                    width: parent.width
                }

                TextField {
                    id: new_course_price_tf
                    placeholderText: "Price"
                    width: parent.width
                }

                Row {
                    width: parent.width
                    spacing: 5

                    TextField {
                        id: new_course_session_start_tf
                        width: parent.width * .5
                        placeholderText: "Session Starts"
                    }

                    TextField {
                        id: new_course_session_ends_tf
                        width: parent.width * .5
                        placeholderText: "Session Ends"
                    }

                }

                Row {
                    width: parent.width
                    spacing: 5

                    CheckBox {
                        id: new_course_has_active_cb
                        text: "HasActive"
                    }

                }

                Row {
                    width: parent.width
                    spacing: 5

                    Label {
                        anchors.verticalCenter: parent.verticalCenter
                        width: parent.width * .3
                        font.pixelSize: 15
                        text: "Space Left"
                    }

                    SpinBox {
                        id: new_course_space_left_sb
                        width: parent.width * .7
                        from: 0
                        to: 50
                    }

                }

                Row {
                    width: parent.width
                    spacing: 5

                    Label {
                        anchors.verticalCenter: parent.verticalCenter
                        width: parent.width * .3
                        font.pixelSize: 15
                        text: "Space Full"
                    }

                    SpinBox {
                        id: new_course_space_full_sb
                        width: parent.width * .7
                        from: 0
                        to: 50
                    }

                }

                Button {
                    text: "Create"
                    width: parent.width
                    onClicked: {
                        if (isCreateNewCourseFormValid()) {
                            page_controller.createNewCourse(getCreateNewCourseFormData());
                            resetCreateNewCourseForm();
                            create_new_course_form.close()
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

}
