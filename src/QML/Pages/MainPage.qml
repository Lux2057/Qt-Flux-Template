import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15

import Flux 1.0

import "qrc:///QML"
import "qrc:///QML/Pages/Base"

Page {
    readonly property PageVM vm: PageVM {
        uid: NavigationRoutes.mainPage
    }

    QtObject {
        id: innerVM
    }

    Column {

        spacing: 15

        anchors.fill: parent

        Label {
            id: titleLbl

            anchors.horizontalCenter: parent.horizontalCenter

            text: "Main page"
        }

        Label {
            id: counterLbl

            anchors.horizontalCenter: parent.horizontalCenter

            text: "Counter: " + MainStore.counter
        }

        Row {
            spacing: 10

            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                id: decrementCounterBtn

                width: Style.controls.buttonWidth
                height: Style.controls.buttonHeight

                text: "-1"

                onPressed: ActionProvider.setCounter(MainStore.counter - 1)
            }

            Button {
                id: incrementCounterBtn

                width: Style.controls.buttonWidth
                height: Style.controls.buttonHeight

                text: "+1"

                onPressed: ActionProvider.setCounter(MainStore.counter + 1)
            }
        }

        Button {
            id: backButton

            anchors.horizontalCenter: parent.horizontalCenter

            width: Style.controls.buttonWidth
            height: Style.controls.buttonHeight

            text: "Information page"

            onClicked: NavigationActionProvider.setPage(
                           NavigationRoutes.informationPage)
        }
    }
}
