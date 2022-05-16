import QtQuick 2.0

// Model determins what data is in the list

ListModel {
    id: colorModel

    ListElement {
        name: "Black"
        code: "#000000"
    }

    ListElement {
        name: "White"
        code: "#FFFFFF"
    }

    ListElement {
        name: "Red"
        code: "#FF0000"
    }

    ListElement {
        name: "Blue"
        code: "#0000FF"
    }

    ListElement {
        name: "Green"
        code: "#00FF00"
    }

    ListElement {
        name: "Yellow"
        code: "yellow"
    }

}
