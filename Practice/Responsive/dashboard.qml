import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    visible: true

    property int default_pix_density: 4
    property double scale_factor: 1.2 // Screen.pixelDensity / default_pix_density

    property int responsiveWidth: 600 * scale_factor
    width: 800 * scale_factor; height: 500 * scale_factor;
    minimumWidth: 400 * scale_factor; minimumHeight:  400 * scale_factor;

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
                        font.bold: true
                        text: "Gupta Book Stores"
                        wrapMode: Label.WordWrap
                        font.pointSize: 20 * scale_factor
                        width: parent.width - (parent.padding * 2)
                    }

                    Label {
                        text: "Jamshedpur"
                        wrapMode: Label.WordWrap
                        font.pointSize: 10 * scale_factor
                        width: parent.width - (parent.padding * 2)
                    }

                }

                Image {
                    id: qr_code
                    width: 80 * scale_factor
                    height: 80 * scale_factor
                    anchors.right: parent.right
                    anchors.rightMargin: 30 * scale_factor
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/images/images/raisehand_sample_qr.png"
                }

            }

            Rectangle {
                height: second_column.height
                width: parent.width
                color: "black"

                Column {
                    width: parent.width
                    id: second_column
                    spacing: 10
                    padding: 50

                    Row {
                        width: parent.width - (parent.padding * 2)

                        Label {
                            font.bold: true
                            id: notice_borad_lbl
                            text: "Notice Board"
                            wrapMode: Label.WordWrap
                            font.pointSize: 20 * scale_factor
                            width: parent.width - notice_borad_change_btn.width
                        }

                        Button {
                            id: notice_borad_change_btn
                            text: "Change"
                        }

                    }

                    Label {
                        wrapMode: Label.WordWrap
                        font.pointSize: 10 * scale_factor
                        width: parent.width - (parent.padding * 2)
                        text: "In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available. It is also used to temporarily replace text in a process called greeking, which allows designers to consider the form of a webpage or publication, without the meaning of the text influencing the design."
                    }

                }

            }

            Rectangle {
                height: third_column.height
                width: parent.width
                color: "black"

                Column {
                    width: parent.width
                    id: third_column
                    spacing: 10
                    padding: 50

                    Row {
                        width: parent.width - (parent.padding * 2)

                        Column {
                            width: parent.width - showcase_swap_btn.width
                            spacing: 2

                            Label {
                                font.bold: true
                                id: showcase_lbl
                                text: "Showcase"
                                wrapMode: Label.WordWrap
                                font.pointSize: 20 * scale_factor
                            }

                            Label {
                                id: showcase_sub_lbl
                                wrapMode: Label.WordWrap
                                font.pointSize: 10 * scale_factor
                                text: "These products will be shown to public feed."
                            }

                        }

                        Button {
                            id: showcase_swap_btn
                            text: "Swap Showcase"
                            onClicked: {
                                console.log("Send Network Request To Swap The Showcase, & freeze this action")
                            }
                        }

                    }

                    ListView {
                        model: 3
                        clip: true
                        spacing: 5
                        width: parent.width
                        height: 150 * scale_factor
                        orientation: ListView.Horizontal
                        delegate: SingleRepoProductItem {
                            $preferredHeight: 150
                            $preferredWidth: 150
                            $height: 150
                            $width: 150
                        }
                    }

                }

            }

            Rectangle {
                height: fourth_column.height
                width: parent.width
                color: "black"

                Column {
                    width: parent.width
                    id: fourth_column
                    spacing: 10
                    padding: 50

                    Row {
                        width: parent.width - (parent.padding * 2)

                        Column {
                            width: parent.width - days_open_checkboxes_grid.width
                            spacing: 2

                            Label {
                                font.bold: true
                                id: owner_lbl
                                text: "Owner"
                                wrapMode: Label.WordWrap
                                font.pointSize: 20 * scale_factor
                            }

                            Label {
                                id: owner_name_lbl
                                wrapMode: Label.WordWrap
                                font.pointSize: 10 * scale_factor
                                text: "Vinod Kumar Gupta"
                            }

                        }

                        Grid {
                            id: days_open_checkboxes_grid
                            columns: 3

                            CheckBox {
                                enabled: false
                                checked: true
                                text: "Monday"
                            }

                            CheckBox {
                                enabled: false
                                checked: true
                                text: "Tuesday"
                            }

                            CheckBox {
                                enabled: false
                                checked: true
                                text: "Wednesday"
                            }

                            CheckBox {
                                enabled: false
                                checked: true
                                text: "Thrusday"
                            }

                            CheckBox {
                                enabled: false
                                checked: true
                                text: "Friday"
                            }

                            CheckBox {
                                enabled: false
                                checked: true
                                text: "Satarday"
                            }

                            CheckBox {
                                enabled: false
                                checked: false
                                text: "Sunday"
                            }

                        }

                    }

                }

            }

            Rectangle {
                height: fifth_column.height
                width: parent.width
                color: "black"

                Column {
                    width: parent.width
                    id: fifth_column
                    spacing: 10
                    padding: 50

                    Row {
                        width: parent.width - (parent.padding * 2)

                        Column {
                            width: parent.width - edit_shop_btn.width
                            spacing: 2

                            Label {
                                font.bold: true
                                id: basic_info_lbl
                                text: "Basic Information"
                                wrapMode: Label.WordWrap
                                font.pointSize: 20 * scale_factor
                            }

                        }

                        Button {
                            id: edit_shop_btn
                            text: "Edit"
                            onClicked: {

                            }
                        }

                    }

                    Label {
                        wrapMode: Label.WordWrap
                        font.pointSize: 10 * scale_factor
                        width: parent.width - (parent.padding * 2)
                        text: "08:00 to 20:00"
                    }

                    Label {
                        wrapMode: Label.WordWrap
                        font.pointSize: 10 * scale_factor
                        width: parent.width - (parent.padding * 2)
                        text: "Cash • Paytm • PhonePay • GooglePay"
                    }

                    Label {
                        wrapMode: Label.WordWrap
                        font.pointSize: 10 * scale_factor
                        width: parent.width - (parent.padding * 2)
                        text: "GST:- "
                    }

                }

            }

            Rectangle {
                height: sixth_column.height
                width: parent.width
                color: "black"

                Column {
                    width: parent.width
                    id: sixth_column
                    spacing: 10
                    padding: 50

                    Row {
                        width: parent.width - (parent.padding * 2)

                        Column {
                            width: parent.width - edit_shop_btn.width
                            spacing: 2

                            Label {
                                font.bold: true
                                id: about_lbl
                                text: "About"
                                wrapMode: Label.WordWrap
                                font.pointSize: 20 * scale_factor
                            }

                        }

                    }

                    Label {
                        wrapMode: Label.WordWrap
                        font.pointSize: 10 * scale_factor
                        width: parent.width - (parent.padding * 2)
                        text: "We keep stationery good for school/college students. We also have office use product, recharge, paper, lamination, xerox."
                    }

                }

            }

            Rectangle {
                height: seventh_column.height
                width: parent.width
                color: "black"

                Column {
                    width: parent.width
                    id: seventh_column
                    spacing: 10
                    padding: 50

                    Row {
                        width: parent.width - (parent.padding * 2)

                        Column {
                            width: parent.width - edit_shop_btn.width
                            spacing: 2

                            Label {
                                font.bold: true
                                id: deals_with_lbl
                                text: "Deals with"
                                wrapMode: Label.WordWrap
                                font.pointSize: 20 * scale_factor
                            }

                        }

                    }

                    Label {
                        wrapMode: Label.WordWrap
                        font.pointSize: 10 * scale_factor
                        width: parent.width - (parent.padding * 2)
                        text: "Stationery & Books | Toys & Games | More..."
                    }

                }

            }

        }

    }

}
