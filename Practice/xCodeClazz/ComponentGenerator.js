// @Required - your context must have these signal(s)
// SIGNALS:
//      openCountState(string name, string count)
// PROPERTIES
//      i: int
//      __parent__: ElementId
//      obj: { name: String, count: String }
function createCountState(i, obj, __parent__) {
    Qt.createQmlObject(`

       import QtQuick 2.0;
       import QtQuick.Layouts 1.3;
       import QtQuick.Controls 2.3;

       Rectangle {
           id: createCountState_${i};
           width: 150;
           height: 150;
           border.color: "black";

           MouseArea {
               anchors.fill: parent;
               onClicked: {
                   openCountState("${obj.name}", "${obj.count}")
               }
           }

           ColumnLayout {
               width: parent.width;
               anchors.fill: parent;
               Layout.alignment: Qt.AlignVCenter | Qt.AlignHCenter;

               Text {
                   Layout.alignment: Qt.AlignHCenter;
                   text: qsTr("${obj.count}");
                   font.pointSize: 30;
               }

               Text {
                   Layout.alignment: Qt.AlignHCenter;
                   text: qsTr("${obj.name}");
                   font.pointSize: 18;
                   font.bold: true;
               }

           }
       }

       ` , __parent__, `createCountState(${i})`);
}

// @Required - your context must have these signal(s)
// SIGNALS:
//      openCourse(string id, string name)
// PROPERTIES
//      i: int
//      __parent__: ElementId
//      obj: { name: String, id: String, url: string }
function createCourseCard(i, obj, __parent__) {
    Qt.createQmlObject(`

        import QtQuick 2.0;
        import QtQuick.Controls 2.3;

        Rectangle {
            id: createCourseCard_${i};
            clip: true;
            width: 200;
            height: 200;
            border.color: "black";

            Column {
                width: parent.width;
                anchors.fill: parent;
                height: parent.height;

                Image {
                    source: "${obj.url}";
                    height: parent.height - 30;
                    width: parent.width;
                    fillMode: Image.PreserveAspectFit;
                }

                Button {
                    text: "${obj.name}";
                    width: parent.width;
                    highlighted: true;
                    height: 30;
                    onClicked: {
                        openCourse("${obj.id}", "${obj.name}");
                    }
                }

            }
        }` , __parent__, `createCourseCard(${i})`);
}
