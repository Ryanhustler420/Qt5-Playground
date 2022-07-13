import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    visible: true

    property int default_pix_density: 4
    property double scale_factor: 1.2 // Screen.pixelDensity / default_pix_density

    property int responsiveWidth: 600 * scale_factor
    width: 800 * scale_factor; height: 500 * scale_factor;
    minimumWidth: 400 * scale_factor; minimumHeight:  400 * scale_factor;

    Column {
        anchors.fill: parent
        spacing: 20

        Rectangle {
            height: first_column.height
            width: parent.width
            color: "black"

            Column {
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width
                id: first_column
                spacing: 10
                padding: 50

                Label {
                    text: "Library"
                    wrapMode: Label.WordWrap
                    font.pointSize: 20 * scale_factor
                    width: parent.width - (parent.padding * 2)
                }

                Label {
                    color: "green"
                    text: "Connected"
                    font.bold: true
                    wrapMode: Label.WordWrap
                    font.pointSize: 10 * scale_factor
                    width: parent.width - (parent.padding * 2)
                }

            }

            Row {
                anchors.right: parent.right
                anchors.rightMargin: 30 * scale_factor
                anchors.verticalCenter: parent.verticalCenter
                spacing: 10

                TextField { placeholderText: "Search keyword, snapshot"; width: 150 * scale_factor }
                Button { text: "Search" }

            }

        }

        C1.SplitView {
            height: parent.height - first_column.height
            Item {
                width: 600

                ScrollView {
                    clip: true
                    width: parent.width
                    height: parent.height
                    ScrollBar.vertical: ScrollBar {
                        height: 0
                        id: scroll_handle
                        onPositionChanged: {
                            if (scroll_handle.position + scroll_handle.size == 1) {
                            }
                        }
                    }

                    Flow {
                        width: parent.width
                        spacing: 15
                        padding: 10

                        SingleRepoProductItem {
                            $preferredHeight: 100
                            $preferredWidth: 100
                            $height: 100
                            $width: 100
                        }

                        SingleRepoProductItem {
                            $preferredHeight: 100
                            $preferredWidth: 100
                            $height: 100
                            $width: 100
                        }

                    }

                }
            }

            Item {
                width: 400
                StackView {
                    width: parent.width
                    height: parent.height
                    initialItem: "qrc:/import_single_repo_product.qml"
                }
            }
        }

    }

}
