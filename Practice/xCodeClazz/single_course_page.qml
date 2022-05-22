import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

import com.xcodeclazz.singlecoursepagecontroller 1.0

Page {
    id: root
    Layout.fillHeight: true
    Layout.fillWidth: true
    title: qsTr("xCodeClazz")
    Component.onCompleted: {
        // every component can have stackView

        // if login page removed from stack view, then gotopage can't call
        // first go to that page and then remove the stack below
    }

    // first complete the flow of the ui
    // put the routes and internet connection/login
    // put db login as well
    // figure out the design pattern and use that in another project

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
            height: parent.height * .5
            onWidthChanged: {
                width: parent.width
                height: parent.height * .5
            }

            Column {
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: parent.width * .3
                height: parent.height
                onWidthChanged: {
                    width: parent.width * .3
                    height: parent.height
                }

                Image {
                    id: name
                    source: "http://xcodeclazz.com/assets/cpp_icon.svg" // "qrc:/images/oCopy.png"
                    height: parent.height
                    width: parent.width
                    fillMode: Image.PreserveAspectFit
                    onWidthChanged: {
                        height: parent.height
                        width: parent.width
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
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    height: parent.height
                    width: parent.width
                    spacing: 20
                    onWidthChanged: {
                        height: parent.height
                        width: parent.width
                    }

                    Text {
                        id: title
                        font.bold: true
                        width: parent.width
                        font.pointSize: 25
                        wrapMode: Text.WordWrap
                        Layout.alignment: Qt.AlignHCenter
                        text: qsTr("C++ For Complete Beginner")
                        onWidthChanged: {
                            width: parent.width
                        }
                    }

                    Text {
                        id: subtitle
                        color: "gray"
                        width: parent.width
                        font.pointSize: 15
                        wrapMode: Text.WordWrap
                        Layout.alignment: Qt.AlignHCenter
                        text: qsTr("Language of machine infact robots")
                        onWidthChanged: {
                            width: parent.width
                        }
                    }

                    Text {
                        id: price
                        color: "green"
                        width: parent.width
                        font.pointSize: 13
                        wrapMode: Text.WordWrap
                        Layout.alignment: Qt.AlignHCenter
                        text: qsTr("₹3000")
                        onWidthChanged: {
                            width: parent.width
                        }
                    }

                    Column {
                        id: features
                        Component.onCompleted: {
                            var _features = ["Weekly Coding Challenge", "Coding Group", "Dry Run Practice"]
                            for(var i=0; i < _features.length; i++) {
                                Qt.createQmlObject(`import QtQuick 2.0; import QtQuick.Controls 2.5; Text { text: "${_features[i]}"; font.pointSize: 12; }`, features, "something")
                            }
                        }
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
                            highlighted: true
                            onClicked: {
                                console.log("Edit")
                            }
                        }

                        Button {
                            flat: true
                            text: "Delete"
                            highlighted: true
                            onClicked: {
                                popup.open()
                                console.log("Delete")
                            }
                        }

                    }

                }

            }

        }

        Row {
            clip: true
            width: parent.width
            height: parent.height * .5
            onWidthChanged: {
                width: parent.width
                height: parent.height * .5
            }

            Column {
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: parent.width * .3
                height: parent.height
                onWidthChanged: {
                    width: parent.width * .3
                    height: parent.height
                }

                Rectangle {
                    height: parent.height
                    width: parent.width
                    onWidthChanged: {
                        height: parent.height
                        width: parent.width
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
                    clip: true
                    width: parent.width
                    onWidthChanged: {
                        width: parent.width
                    }
                    spacing: 20

                    Text {
                        width: parent.width
                        font.pointSize: 25
                        wrapMode: Text.WordWrap
                        text: "About"
                    }

                    Text {
                        width: parent.width
                        font.pointSize: 10
                        wrapMode: Text.WordWrap
                        text: "In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available"
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

    SingleCoursePageController {
        id: page_controller
    }

}
