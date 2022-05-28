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

    // these functions are being used in this page
    function openCourse(object) {
        page_controller.hold(JSON.stringify(object))
        application.gotoPage(application.getSingleCoursePagePath())
    }

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
        height: parent.height
        anchors.fill: parent
        width: parent.width
        visible: true
        padding: 10
        onWidthChanged: {
            couses_list.width = width
        }

        Column {
            id: couses_list
            clip: true
            width: parent.width
            spacing: 20

            Label {
                width: parent.width
                font.pointSize: 12
                wrapMode: Text.WordWrap
                text: "Following are the courses you are providing to all of your bright student(s) "
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
                placeholderText: "Title"
                width: parent.width
            }

            TextField {
                placeholderText: "Subtitle"
                width: parent.width
            }

            TextField {
                placeholderText: "Duration 3 Months"
                width: parent.width
            }

            TextField {
                placeholderText: "Thumbnail Slug /assts/img.png"
                width: parent.width
            }

            TextField {
                placeholderText: "Features | One | By | One"
                width: parent.width
            }

            TextField {
                placeholderText: "Price"
                width: parent.width
            }

            Row {
                width: parent.width
                spacing: 5

                TextField {
                    width: parent.width * .5
                    placeholderText: "Session Starts"
                }

                TextField {
                    width: parent.width * .5
                    placeholderText: "Session Ends"
                }

            }

            Row {
                width: parent.width
                spacing: 5

                CheckBox {
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
                    width: parent.width * .7
                    from: 0
                    to: 50
                }

            }

            Button {
                text: "Create"
                width: parent.width
                onClicked: {
                    create_new_course_form.close()
                }
            }

        }

    }

    AllCoursesPageController {
        id: page_controller
        onCoursesLoaded: {
            for(var i =0; i< courses.length; i++) {
                ComponentGenerator.createCourseCard(i, JSON.parse(JSON.stringify(courses[i])), application.getSiteAssetsUrl(), coursesContainer);
            }
        }
        onHolded: {
            // console.log(o);
        }
    }

    Component.onCompleted: {
        page_controller.loadCourses()
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
