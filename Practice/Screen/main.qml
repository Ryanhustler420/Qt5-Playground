import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import QtGraphicalEffects 1.0

ApplicationWindow {
    width: 400
    height: 600
    visible: true
    color: "#202124"
    title: qsTr("Properties | Raisehand")

    Flow {
        spacing: 30
        width: parent.width
        height: parent.height

        Rectangle {
            height: 100
            color: "#303134"
            width: parent.width

            DropShadow {
                anchors.fill: source
                cached: true
                horizontalOffset: 0
                verticalOffset: 2
                radius: 9.0
                samples: 16
                color: "#aa000000"
                smooth: true
                source: parent
            }

            Column {
                padding: 10
                spacing: 10

                Label {
                    text: "Screen Resolution"
                    font.pointSize: 15
                    color: "white"
                    font.bold: true
                }

                Label {
                    text: system.getScreenSize()
                    color: "white"
                }

            }

        }

        Rectangle {
            height: 300
            color: "#303134"
            width: parent.width

            //            DropShadow {
            //                anchors.fill: source
            //                cached: true
            //                horizontalOffset: 0
            //                verticalOffset: 2
            //                radius: 9.0
            //                samples: 16
            //                color: "#000000"
            //                smooth: true
            //                source: parent
            //            }

            Column {
                padding: 10
                spacing: 10

                Label {
                    id: ps_size_lbl
                    text: "Change the slider"
                    color: "white"
                }

                Slider {
                    to: 100
                    from: 1
                    value: ps_lbl.font.pointSize
                    onPositionChanged: {
                        ps_lbl.font.pointSize = Math.round(value)
                        ps_size_lbl.text = "Point Size: " + Math.round(value)
                    }
                }

                Label {
                    id: ps_lbl
                    text: "Text"
                    font.pointSize: 15
                    color: "white"
                    font.bold: true
                }

            }

        }

    }

    // display the currect screen resultion
    // display image size effect on different screen
    // display slider to resize the font size

}
