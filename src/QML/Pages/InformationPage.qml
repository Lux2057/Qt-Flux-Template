import QtQuick 2.15
import QtQuick.Controls 2.15

import Flux 1.0

import "qrc:///QML"
import "qrc:///QML/Pages/Base"

Page {
    readonly property PageVM vm: PageVM {
        uid: NavigationRoutes.informationPage
    }

    Column {

        spacing: 15

        anchors.fill: parent

        Label {
            id: titleLbl

            text: "Information page"
        }

        Label {
            id: counterLbl

            text: "Counter: " + MainStore.counter
        }

        Text {
            id: infoTxt

            width: parent.width

            anchors.horizontalCenter: parent.horizontalCenter

            padding: 5

            text: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur.
Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."

            font.pointSize: 10
        }

        Button {
            id: backButton

            anchors.horizontalCenter: parent.horizontalCenter

            width: 70
            height: 30

            text: "Close page"

            onClicked: NavigationActionProvider.closeCurrentPage()
        }
    }
}
