import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2

import software.raisehand.backend 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Raisehand Editor")

    // Our own class backend
    Backend {
        id: backendClass
        onPathChanged: {
            console.log("onPathChanged::", "Path has been changed to", path)
        }
        onDataChanged: {
            console.log("onDataChanged::", "Path has been changed to", path)
        }
    }

    FileDialog {
        id: openDialog
        title: "Please choose a file"
        folder: shortcuts.home
        selectMultiple: false
        selectExisting: true

        onAccepted: {
            backendClass.path = openDialog.fileUrl
            editor.text = backendClass.data
        }
    }

    FileDialog {
        id: saveDialog
        title: "Please choose a file"
        folder: shortcuts.home
        selectMultiple: false
        selectExisting: false

        onAccepted: {
            backendClass.path = saveDialog.fileUrl
            backendClass.data = editor.text
        }
    }

    Action {
        id: actionNew
        text: qsTr("New")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oNew.png"
        onTriggered: {
            editor.clear()
        }
    }

    Action {
        id: actionOpen
        text: qsTr("Open")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oOpen.png"
        onTriggered: {
            openDialog.open()
        }
    }

    Action {
        id: actionSave
        text: qsTr("Save")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oSave.png"
        onTriggered: {
            saveDialog.open()
        }
    }

    Action {
        id: actionCopy
        text: qsTr("Copy")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oCopy.png"
        onTriggered: {
            editor.copy()
        }
    }

    Action {
        id: actionCut
        text: qsTr("Cut")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oCut.png"
        onTriggered: {
            editor.cut()
        }
    }

    Action {
        id: actionPaste
        text: qsTr("Paste")
        icon.color: "transparent"
        icon.source: "qrc:/flat/outlines/oPaste.png"
        onTriggered: {
            editor.paste()
        }
    }

    menuBar: MenuBar {
        Menu {
            id: menuFile
            title: "File"
            MenuItem { action: actionNew }
            MenuItem { action: actionOpen }
            MenuItem { action: actionSave }
        }

        Menu {
            id: menuEdit
            title: "Edit"
            MenuItem { action: actionCopy }
            MenuItem { action: actionCut }
            MenuItem { action: actionPaste }
        }
    }

    header: ToolBar {

        Row {
            ToolButton { display: AbstractButton.IconOnly; action: actionNew }
            ToolButton { display: AbstractButton.IconOnly; action: actionOpen }
            ToolButton { display: AbstractButton.IconOnly; action: actionSave }
            ToolButton { display: AbstractButton.IconOnly; action: actionCopy }
            ToolButton { display: AbstractButton.IconOnly; action: actionCut }
            ToolButton { display: AbstractButton.IconOnly; action: actionPaste }
        }

    }

    ScrollView {
        anchors.fill: parent
        TextArea {
            id: editor
            focus: true
            text: "Hello, World"
            selectByMouse: true
            persistentSelection: true // copy and paste need this
        }
    }

}
