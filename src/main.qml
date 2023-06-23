import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

import Flux 1.0

import "qrc:///QML/Pages/Base"
import "qrc:///QML"
import "qrc:///QML/Pages"

Window {
    minimumWidth: Style.window.minWidth
    minimumHeight: Style.window.minHeight
    maximumWidth: Style.window.maxWidth
    maximumHeight: Style.window.maxHeight
    visible: true
    title: qsTr("Qt-Flux-Template")

    property var navigationPagesStack: NavigationStore.pagesStack
    onNavigationPagesStackChanged: {

        var itemInStack = pagesStackView.find(function (item, index) {
            return item.vm.uid === NavigationStore.currentPage
        })

        var existsInStack = itemInStack != null

        var page
        switch (NavigationStore.currentPage) {
        case NavigationRoutes.mainPage:
            page = mainPage
            break
        case NavigationRoutes.informationPage:
            page = informationPage
            break
        }

        if (page == null)
            return

        if (existsInStack) {
            pagesStackView.pop(page)
        } else {
            pagesStackView.push(page)
        }
    }

    StackView {
        id: pagesStackView

        anchors.fill: parent

        Component.onCompleted: NavigationActionProvider.setPage(
                                   NavigationRoutes.mainPage)
    }

    MainPage {
        id: mainPage
        visible: false
    }

    InformationPage {
        id: informationPage
        visible: false
    }
}
