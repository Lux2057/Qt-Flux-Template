import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Flux 1.0

import "qrc:///QML"

Window {
    minimumWidth: Style.window.minWidth
    minimumHeight: Style.window.minHeight
    maximumWidth: Style.window.maxWidth
    maximumHeight: Style.window.maxHeight
    visible: true
    title: qsTr("Qt-Flux-Template")

    Column {
        id: counterContainer

        width: parent.width
        height: parent.height

        Text {
            id: counterValue

            anchors.horizontalCenter: parent.horizontalCenter

            text: MainStore.counter
        }

        Row {
            id: controlsContainer

            anchors.horizontalCenter: parent.horizontalCenter

            padding: 5
            spacing: 5

            Button {
                id: incrementCounterBtn

                width: 40
                height: 30

                onPressed: ActionProvider.setCounter(MainStore.counter + 1)

                text: "+1"
            }

            Button {
                id: decrementCounterBtn

                width: 40
                height: 30

                onPressed: ActionProvider.setCounter(MainStore.counter - 1)

                text: "-1"
            }
        }
    }
}
