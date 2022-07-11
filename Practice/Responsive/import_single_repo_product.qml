import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    visible: true

    property int responsiveWidth: 600
    property int default_pix_density: 4
    property int scale_factor: Screen.pixelDensity / default_pix_density

    minimumWidth: 400; minimumHeight:  400;
    width: 800; height: 500;

    Item {
        states: [
            State {
                when: window.width <= responsiveWidth
                PropertyChanges {
                    target: repo_product_img_large
                    parent: repo_product_img_tiny_container
                }
            }
        ]
    }

    ScrollView {
        clip: true
        contentWidth: -1
        height: parent.height
        anchors.fill: parent
        width: parent.width
        visible: true
        padding: 0
        onWidthChanged: {
        }
        ScrollBar.vertical: ScrollBar {
            id: scroll_handle
            height: 0
            onPositionChanged: {
                if (scroll_handle.position + scroll_handle.size == 1) {
                }
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter
            anchors.fill: parent

            RowLayout {
                Layout.preferredWidth: parent.width
                Layout.fillWidth: true
                Layout.margins: 50
                spacing: 10

                ColumnLayout {
                    Layout.alignment: Qt.AlignTop
                    Layout.preferredWidth: 60
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    spacing: 20

                    ColumnLayout {
                        id: repo_product_img_tiny_container
                        Layout.alignment: Qt.AlignTop
                        Layout.fillWidth: true
                    }

                    Label {
                        text: "Dolo 650 Tablets"
                        wrapMode: Label.WordWrap
                        Layout.fillWidth: true
                        font.pointSize: 25
                        font.bold: true
                    }

                    ColumnLayout {
                        Layout.alignment: Qt.AlignTop
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Label {
                            text: "Cipla India Ltd."
                            wrapMode: Label.WordWrap
                            Layout.fillWidth: true
                            font.pointSize: 10
                            font.bold: false
                        }

                        Label {
                            text: "#2245"
                            wrapMode: Label.WordWrap
                            Layout.fillWidth: true
                            font.pointSize: 10
                            font.bold: false
                            color: "gray"
                        }

                    }

                    RowLayout {
                        Layout.alignment: Qt.AlignTop
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Label {
                            font.bold: true
                            font.pointSize: 13
                            text: "25K\nImports"
                            Layout.preferredWidth: 100
                        }

                        Label {
                            font.bold: true
                            font.pointSize: 13
                            text: "335K\nViews"
                            Layout.preferredWidth: 100
                        }

                        Label {
                            font.bold: true
                            font.pointSize: 13
                            text: "98.36\nPrice"
                            Layout.preferredWidth: 100
                        }

                    }

                    RowLayout {
                        Layout.alignment: Qt.AlignTop
                        Layout.fillHeight: true
                        Layout.fillWidth: true

                        Button {
                            text: "Import"
                            onClicked: {

                            }
                        }

                        Button {
                            text: "Raise Issue"
                            onClicked: {

                            }
                        }

                        RoundButton {
                            text: "\u2026"
                            onClicked: {

                            }
                        }

                    }

                }

                ColumnLayout {
                    Layout.alignment: Qt.AlignTop
                    Layout.preferredWidth: 40
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    Image {
                        width: 200; height: 200;
                        id: repo_product_img_large
                        fillMode: Image.PreserveAspectFit
                        source: "https://play-lh.googleusercontent.com/WR3T4fGcfBDwU1JCPuo0dBPXavvEA7FA_pS0oLNQcWxX85aUyRc8pVdqdkiL-DADZA0n=w240-h480-rw"
                    }

                }

            }

            ColumnLayout {
                Layout.preferredWidth: parent.width
                Layout.fillWidth: true
                Layout.margins: 50
                spacing: 10

                Label {
                    text: "About"
                    font.bold: true
                    font.pointSize: 20
                    Layout.fillWidth: true
                    wrapMode: Label.WordWrap
                }

                Label {
                    text: "In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available. It is also used to temporarily replace text in a process called greeking, which allows designers to consider the form of a webpage or publication, without the meaning of the text influencing the design."
                    wrapMode: Label.WordWrap
                    Layout.fillWidth: true
                }

            }

            RowLayout {
                Layout.preferredWidth: parent.width
                Layout.fillWidth: true
                Layout.margins: 50
                spacing: 10

                Rectangle {
                    Layout.preferredWidth: 30
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: "black"
                    height: 200
                    width: 200
                }

                Rectangle {
                    Layout.preferredWidth: 30
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: "black"
                    height: 200
                    width: 200
                }

                Rectangle {
                    Layout.preferredWidth: 30
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    color: "black"
                    height: 200
                    width: 200
                }

            }

            ColumnLayout {
                Layout.preferredWidth: parent.width
                Layout.fillWidth: true
                Layout.margins: 50
                spacing: 10

                Label {
                    text: "Updated"
                    font.bold: true
                    font.pointSize: 20
                    Layout.fillWidth: true
                    wrapMode: Label.WordWrap
                }

                Label {
                    text: "32 Min ago"
                    wrapMode: Label.WordWrap
                    Layout.fillWidth: true
                }

            }

        }

    }

}
