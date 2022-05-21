import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import com.xcodeclazz.allcoursespagecontroller 1.0
import "qrc:/js/ComponentGenerator.js" as ComponentGenerator

Page {
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true
    title: qsTr("xCodeClazz")

    // these signals are being used in this page
    signal openCourse(string id, string name);
    onOpenCourse: {
        page_controller.hold(name, id, "QString duration", "QString thumbnailUrl", "QString imageContainer", [], 123, false, 0, 8, "QString starts", "QString ends")
        application.gotoPage(application.getSingleCoursePagePath())
    }

    header: Rectangle {
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

        TextField {
            id: search_field
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.margins: 10
            placeholderText: "Search\u2026"
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

            Text {
                width: parent.width
                font.pointSize: 12
                wrapMode: Text.WordWrap
                text: "Following are the courses you are providing to all of your bright student(s) "
            }

            Flow {
                id: courses
                width: parent.width
                spacing: 15

                Component.onCompleted: {
                    var list = [
                                { name: "Java", id: "5", url: "http://xcodeclazz.com/assets/java-icon.svg" },
                                { name: "Python", id: "15", url: "http://xcodeclazz.com/assets/python-icon.svg" },
                                { name: "NodeJS", id: "15", url: "http://xcodeclazz.com/assets/nodejs-icon.svg" },
                                { name: "C++", id: "15", url: "http://xcodeclazz.com/assets/cpp_icon.svg" },
                            ]
                    for(var i =0; i< list.length; i++) {
                        ComponentGenerator.createCourseCard(i, list[i], courses);
                    }
                }

            }

        }
    }

    AllCoursesPageController {
        id: page_controller
    }

}
