import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

import com.xcodeclazz.singlecoursepagecontroller 1.0

Page {
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true
    title: qsTr("xCodeClazz")

    Component.onCompleted: {

    }

    Column {
        width: parent.width
        height: parent.height
        onWidthChanged: {
            width: parent.width
            height: parent.height
        }

        Row {
            clip: true
            width: parent.width
            height: parent.height * .6
            onWidthChanged: {
                width: parent.width
                height: parent.height * .6
            }

            Column {
                width: parent.width * .3
                height: parent.height
                onWidthChanged: {
                    width: parent.width * .3
                    height: parent.height
                }

                Loader {
                    id: course_img_loader
                    visible: status == Loader.Ready
                    height: 200
                    width: 200
                    asynchronous: true
                    anchors.horizontalCenter: parent.horizontalCenter;
                    anchors.verticalCenter: parent.verticalCenter;
                }

                BusyIndicator {
                    running: course_img_loader.status === Loader.Loading;
                    id: course_img_loader_busy_animation;
                    height: course_img_loader.height;
                    width: course_img_loader.width;
                    anchors.horizontalCenter: parent.horizontalCenter;
                    anchors.verticalCenter: parent.verticalCenter;

                    Image {
                        id: course_img_loader_placeholder
                        height: parent.height;
                        width: parent.width;
                        fillMode: Image.PreserveAspectFit;
                        anchors.horizontalCenter: parent.horizontalCenter;
                        anchors.verticalCenter: parent.verticalCenter;
                        onWidthChanged: {
                            height: parent.height
                            width: parent.width
                        }
                    }

                }

            }

            ScrollView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: parent.width * .7
                height: parent.height
                onWidthChanged: {
                    width: parent.width * .7
                    height: parent.height
                }

                Column {
                    topPadding: 20
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    height: parent.height
                    width: parent.width
                    spacing: 20
                    onWidthChanged: {
                        height: parent.height
                        width: parent.width
                    }

                    Label {
                        id: title
                        font.bold: true
                        width: parent.width
                        font.pointSize: 25
                        wrapMode: Text.WordWrap
                        Layout.alignment: Qt.AlignHCenter
                        onWidthChanged: {
                            width: parent.width
                        }
                    }

                    Label {
                        id: subtitle
                        color: "gray"
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        Layout.alignment: Qt.AlignHCenter
                        onWidthChanged: {
                            width: parent.width
                        }
                    }

                    Label {
                        id: price
                        color: "green"
                        width: parent.width
                        font.pointSize: 20
                        wrapMode: Text.WordWrap
                        Layout.alignment: Qt.AlignHCenter
                        onWidthChanged: {
                            width: parent.width
                        }
                    }

                    Column {
                        id: features
                        spacing: 5
                    }

                    Row {
                        clip: true
                        width: parent.width
                        spacing: 5
                        onWidthChanged: {
                            width: parent.width
                        }

                        Button {
                            flat: true
                            text: "Edit"
                            Material.background: Material.Green
                            onClicked: {
                                edit_form_popup.open()
                            }
                        }

                        Button {
                            flat: true
                            text: "Delete"
                            Material.background: Material.Red
                            onClicked: {
                                loading_popup.open()
                                page_controller.courseDeleted("_id")
                            }
                        }

                    }

                }

            }

        }

        Row {
            clip: true
            width: parent.width
            height: parent.height * .4
            onWidthChanged: {
                width: parent.width
                height: parent.height * .4
            }

            ScrollView {
                padding: 10
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: parent.width * 1.0 // .7
                height: parent.height
                onWidthChanged: {
                    width: parent.width * 1.0 // .7
                    height: parent.height
                }

                Column {
                    clip: true
                    width: parent.width
                    onWidthChanged: {
                        width: parent.width
                    }
                    spacing: 20

                    Label {
                        width: parent.width
                        font.pointSize: 25
                        wrapMode: Text.WordWrap
                        text: "About"
                    }

                    Label {
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        lineHeight: 1.5
                        text: "In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available"
                    }

                }
            }

            Column {
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: parent.width * 0 // .3
                height: parent.height
                onWidthChanged: {
                    width: parent.width * 0 // .3
                    height: parent.height
                }

                Rectangle {
                    height: parent.height
                    width: parent.width
                    color: "transparent"
                    onWidthChanged: {
                        height: parent.height
                        width: parent.width
                    }

                }

            }

        }
    }

    Popup {
        id: loading_popup
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

    Popup {
        id: edit_form_popup
        modal: true
        focus: true
        anchors.centerIn: parent
        closePolicy: Popup.NoAutoClose

        width: 350

        Column {
            width: parent.width
            spacing: 5

            Label {
                font.bold: true
                font.pointSize: 25
                text: "Course Update"
            }

            TextField {
               placeholderText: "Course Name"
               width: parent.width
            }

            TextField {
               placeholderText: "Course Subtitle"
               width: parent.width
            }

            TextField {
               placeholderText: "Price"
               width: parent.width
               inputMethodHints: Qt.ImhPreferNumbers
            }

            Button {
                text: "Update"
                width: parent.width
                onClicked: {
                    edit_form_popup.close()
                }
            }

        }

    }

    SingleCoursePageController {
        id: page_controller
        onDataReady: {
            // every component can have stackView

            // if login page removed from stack view, then gotopage can't call
            // first go to that page and then remove the stack below

            // first complete the flow of the ui
            // put the routes and internet connection/login
            // put db login as well
            // figure out the design pattern and use that in another project


            // {"course":{"_id":"628346fa96e2e93b132e0e45","duration":"3 Months","features":["Weekly Coding Challenge","Debugging Session","Dry Run Practice","Coding Group"],"hasActive":false,"imageContainer":"raisehand","price":3000,"session":{"ends":"September","starts":"June"},"spaceFull":8,"spaceLeft":0,"subtitle":"The heart of websites","thumbnailUrl":"/assets/js-core-icon.svg","title":"Complete Core JavaScript"}}

            var docs = JSON.parse(JSON.stringify(o))["course"];
            docs['assetsUrl'] = application.getSiteAssetsUrl();

            title.text = docs['title'];
            subtitle.text = docs['subtitle'];
            price.text = docs['price'] + '/-'
            course_img_loader.source = docs['assetsUrl'] + docs['thumbnailUrl'];
            course_img_loader_placeholder.source = docs['assetsUrl'] + docs['thumbnailUrl'];

            for(var i=0; i < docs['features'].length; i++) {
                Qt.createQmlObject(`import QtQuick 2.0; import QtQuick.Controls 2.5; Label { text: "${docs['features'][i]}"; font.pointSize: 12; }`, features, "something")
            }
        }
        onCourseDeleted: {
            console.log(_id);
            loading_popup.close()
        }
    }
}
