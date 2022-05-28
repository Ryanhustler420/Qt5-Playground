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

        TextField {
            id: search_field
            width: 400
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
