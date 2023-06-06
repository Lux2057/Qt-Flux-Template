import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Flux 1.0

Window {
    width: 265
    height: 60
    minimumWidth: 265
    minimumHeight: 60
    maximumWidth: 265
    maximumHeight: 60
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
