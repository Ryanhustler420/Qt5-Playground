import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.3

import com.xcodeclazz.singlecoursepagecontroller 1.0

Page {
    id: root
    Layout.fillWidth: true
    Layout.fillHeight: true
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
            height: parent.height * .5
            onWidthChanged: {
                width: parent.width
                height: parent.height * .5
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
                ScrollBar.vertical: ScrollBar {
                    id: scroll_handle
                    height: 0
                    onPositionChanged: {
                        if (scroll_handle.position + scroll_handle.size == 1) {
                            console.log("Reached Bottom")
                        }
                    }
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

                    Column {
                        width: parent.width
                        onWidthChanged: { width: parent.width }

                        Label {
                            id: duration
                            color: "gray"
                            width: parent.width
                            font.pointSize: 12
                            wrapMode: Text.WordWrap
                            Layout.alignment: Qt.AlignHCenter
                            onWidthChanged: {
                                width: parent.width
                            }
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
            height: parent.height * .5
            onWidthChanged: {
                width: parent.width
                height: parent.height * .5
            }

            ScrollView {
                padding: 10
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: parent.width * 1.0
                height: parent.height
                onWidthChanged: {
                    width: parent.width * 1.0
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
                        lineHeight: 1.2
                        text: "In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available In publishing and graphic design, Lorem ipsum is a placeholder text commonly used to demonstrate the visual form of a document or a typeface without relying on meaningful content. Lorem ipsum may be used as a placeholder before final copy is available"
                    }

                }
            }

            Column {
                Layout.fillHeight: true
                Layout.fillWidth: true
                width: parent.width * 0
                height: parent.height
                onWidthChanged: {
                    width: parent.width * 0
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
        width: 350
        modal: true
        focus: true
        id: edit_form_popup
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
                    text: "Course Update"
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
                            edit_form_popup.close()
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

            // use animation
            // if login page removed from stack view, then gotopage can't call
            // first go to that page and then remove the stack below
            // figure out the design pattern and use that in another project

            var docs = JSON.parse(JSON.stringify(o))["course"];
            docs['assetsUrl'] = application.getSiteAssetsUrl();

            // docs['_id']
            // docs['hasActive']
            // docs['spaceLeft']
            // docs['spaceFull']
            // docs['imageContainer']
            // docs['session']['ends']
            // docs['session']['starts']

            title.text = docs['title'];
            duration.text = docs['duration'];
            subtitle.text = docs['subtitle'];
            price.text = formatMoney(docs['price']) + '/-';
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

        function formatMoney(number, decPlaces, decSep, thouSep) {
            const _decPlaces = isNaN(decPlaces = Math.abs(decPlaces)) ? 2 : decPlaces,
            _decSep = typeof decSep === "undefined" ? "." : decSep;
            thouSep = typeof thouSep === "undefined" ? "," : thouSep;
            var sign = number < 0 ? "-" : "";
            var i = String(parseInt(number = Math.abs(Number(number) || 0).toFixed(_decPlaces)));
            var j = (j = i.length) > 3 ? j % 3 : 0;

            return sign +
                (j ? i.substr(0, j) + thouSep : "") +
                i.substr(j).replace(/(\decSep{3})(?=\decSep)/g, "$1" + thouSep) +
                (_decPlaces ? _decSep + Math.abs(number - i).toFixed(_decPlaces).slice(2) : "");
        }

    }
}
