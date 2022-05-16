import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    Component.onCompleted: {
        $Worker.cppSlot()
    }
}
