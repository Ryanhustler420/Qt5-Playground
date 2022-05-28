// @Required - your context must have these signal(s)
// SIGNALS:
//      openCountState(object o)
// PROPERTIES
//      i: int
//      __parent__: ElementId
//      obj: { name: String, count: String }
function createCountState(i, obj, __parent__) {
    Qt.createQmlObject(`

       import QtQuick 2.0;
       import QtQuick.Layouts 1.3;
       import QtQuick.Controls 2.3;
       import QtQuick.Controls.Material 2.3;

       Item {
           id: createCountState_${i};
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

       ` , __parent__, `createCountState(${i})`);
}

// @Required - your context must have these signal(s)
// FUNCTIONS:
//      signal openCourse(object)
// PROPERTIES
//      i: int
//      obj: { name: String, id: String, thumbnailUrl: String }
//      assetsUrl: string
//      __parent__: ElementId
function createCourseCard(i, obj, assetsUrl, __parent__) {
    Qt.createQmlObject(`

        import QtQuick 2.0;
        import QtQuick.Controls 2.3;
        import QtQuick.Controls.Material 2.3;

        Item {
            id: createCourseCard_${i};
            clip: true;
            width: 200;
            height: 200;

            Column {
                width: parent.width;
                anchors.fill: parent;
                height: parent.height;

                Loader {
                   visible: status == Loader.Ready;
                   id: course_img_loader_${i};
                   height: parent.height - 50;
                   width: parent.width;
                   source: "${assetsUrl}/${obj.thumbnailUrl}";
                   asynchronous: true;
                }

                BusyIndicator {
                   running: course_img_loader_${i}.status === Loader.Loading;
                   id: course_img_loader_busy_animation_${i};
                   height: course_img_loader_${i}.height;
                   width: course_img_loader_${i}.width;

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
                    onClicked: {
                        openCourse(${JSON.stringify(obj)});
                    }
                }

            }
        }` , __parent__, `createCourseCard(${i})`);
}
