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
    onWidthChanged: system.setWindowSize(height, width)
    onHeightChanged: system.setWindowSize(height, width)

    Flow {
        spacing: 30
        width: parent.width
        height: parent.height

        Column {
            spacing: 15
            height: parent.height * .15
            width: parent.width

            Rectangle {
                height: parent.height
                width: parent.width
                color: "#303134"

                Column {
                    width: parent.width
                    padding: 10
                    spacing: 10

                    H1Label {
                        $root.text: "Screen Resolution"
                        $root.color: "white"
                        $root.font.bold: true
                    }

                    H2Label {
                        $root.text: system.getScreenSize()
                        $root.color: "white"
                    }

                }

            }

        }

        Column {
            spacing: 15
            height: parent.height * .5
            width: parent.width

            Rectangle {
                height: parent.height
                width: parent.width
                color: "#303134"

                Column {
                    padding: 10
                    spacing: 10

                    Slider {
                        to: 20
                        from: 10
                        stepSize: 1
                        snapMode: Slider.SnapAlways
                        value: system.getH1FontSize()
                        onPositionChanged: {
                            system.changeH1FontSize(Math.round(value))
                        }
                    }

                    Slider {
                        to: 20
                        from: 10
                        stepSize: 1
                        snapMode: Slider.SnapAlways
                        value: system.getH2FontSize()
                        onPositionChanged: {
                            system.changeH2FontSize(Math.round(value))
                        }
                    }

                    H1Label {
                        $root.text: "H1 Label"
                        $root.color: "white"
                        $root.font.bold: true
                    }

                    H2Label {
                        $root.text: "H2 Label"
                        $root.color: "white"
                    }

                }

            }

        }

    }

    // how to handle rectangle
    // all different screen has different sizes of rect

    // make a dummy ui dashboard to see if the idea presist or not like expension of width
    // and still maintain the ui design and not look bogus

    // what happen when we click `ctrl + +` or `ctrl + -`

    // idea is to have a slider to change entire screen size
    // reflact the change real time
    // we'll have differnert method for all diffrent size

    // we'll show user more information about the system
    // user will send these details to us so that we can analys the system behavior

    // display the currect screen resultion
    // display image size effect on different screen
    // display slider to resize the font size

}
