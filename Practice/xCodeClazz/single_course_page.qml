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
                            page_controller.scrollViewReachedBottom({});
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
                                update_course_form.open()
                            }
                        }

                        Button {
                            flat: true
                            text: "Delete"
                            Material.background: Material.Red
                            onClicked: {
                                page_controller.deleteCourse()
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

    Popup {
        width: 350
        modal: true
        focus: true
        id: update_course_form
        anchors.centerIn: parent
        closePolicy: Popup.NoAutoClose

        ScrollView {
            clip: true
            visible: true
            Layout.fillHeight: true
            Layout.fillWidth: true
            height: parent.height
            width: parent.width
            ScrollBar.vertical: ScrollBar {
                height: 0
            }

            Column {
                width: parent.width
                spacing: 5

                Row {
                    width: parent.width

                    Label {
                        font.bold: true
                        font.pointSize: 20
                        text: "Course Create"
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
                                update_course_form.close()
                            }
                        }

                    }

                }

                TextField {
                    id: update_title_tf
                    placeholderText: "Title"
                    width: parent.width
                }

                TextField {
                    id: update_subtitle_tf
                    placeholderText: "Subtitle"
                    width: parent.width
                }

                TextField {
                    id: update_duration_tf
                    placeholderText: "Duration 3 Months"
                    width: parent.width
                }

                TextField {
                    id: update_thumbnail_tf
                    placeholderText: "Thumbnail Slug /assts/img.png"
                    width: parent.width
                }

                TextField {
                    id: update_features_tf
                    placeholderText: "Features | One | By | One"
                    width: parent.width
                }

                TextField {
                    id: update_price_tf
                    placeholderText: "Price"
                    width: parent.width
                }

                Row {
                    width: parent.width
                    spacing: 5

                    TextField {
                        id: update_session_start_tf
                        width: parent.width * .5
                        placeholderText: "Session Starts"
                    }

                    TextField {
                        id: update_session_ends_tf
                        width: parent.width * .5
                        placeholderText: "Session Ends"
                    }

                }

                Row {
                    width: parent.width
                    spacing: 5

                    CheckBox {
                        id: update_has_active_cb
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
                        id: update_space_left_sb
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
                        id: update_space_full_sb
                        width: parent.width * .7
                        from: 0
                        to: 50
                    }

                }

                Button {
                    text: "Update"
                    width: parent.width
                    onClicked: {
                        if (isUpdateCourseFormValid()) {
                            page_controller.updateCourse(getUpdateCourseFormData());
                            resetUpdateCourseForm();
                            update_course_form.close()
                        }
                    }
                }

            }

        }

    }

    SingleCoursePageController {
        id: page_controller
        onGoBack: application.pop();
        onListViewReached: {}
        onScrollViewReached: {}
        onShowLoading: {
            if (b) {
                popup.open()
            } else {
                popup.close()
            }
        }
        onCourseDeleted: {
            popup.close()
        }
        onCourseLoaded: {
            var docs = JSON.parse(JSON.stringify(o));
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

    }

    Component.onCompleted: {
        page_controller.loadCourse();
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
