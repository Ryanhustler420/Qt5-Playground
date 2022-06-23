// @Required - your context must have these signal(s)
// SIGNALS:
//      openCountState(object o)
// PROPERTIES
//      i: int
//      __parent__: ElementId
//      obj: { name: String, count: String }
function createCountState(id, obj, __parent__) {
    return Qt.createQmlObject(`

       import QtQuick 2.0;
       import QtQuick.Layouts 1.3;
       import QtQuick.Controls 2.3;
       import QtQuick.Controls.Material 2.3;

       Item {
           id: createCountState_${id};
           width: 150;
           height: 150;
           Material.elevation: 6;

           MouseArea {
               anchors.fill: parent;
               onClicked: {
                   openCountState("${obj.name}", "${obj.count}")
               }
           }

           Column {
               spacing: 10;
               width: parent.width;
               anchors.fill: parent;
               Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter;

               Label {
                   Layout.alignment: Qt.AlignHCenter;
                   text: qsTr("${obj.name}");
                   font.pointSize: 18;
               }

               Label {
                   Layout.alignment: Qt.AlignHCenter;
                   text: qsTr("${obj.count}");
                   font.pointSize: 30;
                   font.bold: true;
               }

           }
       }

       ` , __parent__, `createCountState(${id})`);
}

// @Required - your context must have these signal(s)
// FUNCTIONS:
//      signal openCourse(object)
// PROPERTIES
//      i: int
//      obj: { name: String, id: String, thumbnailUrl: String }
//      assetsUrl: string
//      __parent__: ElementId
function createCourseCard(id, obj, assetsUrl, __parent__) {
    return Qt.createQmlObject(`

        import QtQuick 2.0;
        import QtQuick.Controls 2.3;
        import QtQuick.Controls.Material 2.3;
        import QtQuick.Layouts 2.3;

        Rectangle {
            id: createCourseCard_${id};
            clip: true;
            width: 200;
            height: 200;
            radius: 10;
            color: 'transparent';
            border.color: 'white';

            ColumnLayout {
                width: parent.width;
                anchors.fill: parent;
                height: parent.height;

                Loader {
                   visible: status == Loader.Ready;
                   id: course_img_loader_${id};
                   height: parent.height - 50;
                   width: parent.width;
                   source: "${assetsUrl}/${obj.thumbnailUrl}";
                   asynchronous: true;
                }

                BusyIndicator {
                   running: course_img_loader_${id}.status === Loader.Loading;
                   id: course_img_loader_busy_animation_${id};
                   height: course_img_loader_${id}.height;
                   width: course_img_loader_${id}.width;

                   Image {
                       source: "${assetsUrl}/${obj.thumbnailUrl}";
                       height: parent.height;
                       width: parent.width;
                       fillMode: Image.PreserveAspectFit;
                       anchors.horizontalCenter: parent.horizontalCenter;
                       anchors.verticalCenter: parent.verticalCenter;
                   }

                }

                Button {
                    text: "${obj.title}";
                    width: parent.width;
                    anchors.bottom: parent.bottom;
                    onClicked: {
                        openCourse(${JSON.stringify(obj)});
                    }
                }

            }
        }` , __parent__, `createCourseCard(${id})`);
}
