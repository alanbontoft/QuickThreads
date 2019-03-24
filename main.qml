import QtQuick 2.7
// import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.2

import com.company.runner 1.0

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: "Open"
                onClicked: fileDlg.open()

            }
        }
    }

    FileDialog{
        id:fileDlg
        title: "Choose file"
        folder: shortcuts.home
    }

    Runner{
        id: runner
    }

    RowLayout {
        id: rowLayout
        anchors.fill: parent

        Button {
            id: btnStart
            text: "Start"
            font.pointSize: 12
            anchors.left: parent
            anchors.top: parent
            width: 100
            height: 50
            onClicked: {
                runner.start(countValue.text)
            }
        }

        Button {
            id: btnStop
            width: 100
            height: 50
            text: "Stop"
            anchors.top: parent
            font.pointSize: 12
            anchors.left: parent
            onClicked: {
                runner.stop()
            }
        }

        Button {
            id: btnResume
            width: 100
            height: 50
            text: "Resume"
            anchors.top: parent
            font.pointSize: 12
            anchors.left: parent
            onClicked: {
                runner.resume()
            }
        }
    }

    TextField {
        id: countValue
        x: 100
        y: 300
        width: 141
        height: 40
        text: qsTr("Enter start value")
        font.pointSize: 12
        horizontalAlignment: Text.AlignHCenter
    }
}
