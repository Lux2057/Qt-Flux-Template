import QtQuick 2.15
import QtQuick.Controls 2.15
import QtMultimedia 5.15

import Flux 1.0
import QmlProviders 1.0

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

            text: qsTr("Main page")
        }

        Label {
            id: counterLbl

            anchors.horizontalCenter: parent.horizontalCenter

            text: qsTr("Counter") + ": " + MainStore.counter
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

        Row {
            spacing: 10

            anchors.horizontalCenter: parent.horizontalCenter

            Label {
                id: languagePickerLbl

                text: LocalizationService.CHOOSE_LANGUAGE_LT
            }

            ComboBox {
                id: languagePicker

                width: Style.controls.buttonWidth
                height: Style.controls.buttonHeight

                model: [Constants.en_US, Constants.ru_RU]

                Component.onCompleted: LocalizationService.setLanguage(
                                           currentValue)

                onCurrentValueChanged: LocalizationService.setLanguage(
                                           currentValue)
            }
        }

        Button {
            id: backButton

            anchors.horizontalCenter: parent.horizontalCenter

            width: Style.controls.buttonWidth
            height: Style.controls.buttonHeight

            text: qsTr("Information page")

            onClicked: NavigationActionProvider.setPage(
                           NavigationRoutes.informationPage)
        }
    }
}
