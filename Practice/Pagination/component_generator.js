function card(i, __parent__) {
    Qt.createQmlObject(`
       import QtQuick 2.0;
       import QtQuick.Controls 2.3;
       Item {
           id: card_${i};
           clip: true;
           width: 200;
           height: 200;
           Rectangle {
               width: parent.width;
               anchors.fill: parent;
               height: parent.height;
               color: 'red';
           }
       }`, __parent__, `card(${i})`)
}
