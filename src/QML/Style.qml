pragma Singleton

import QtQuick 2.15

import "qrc:///QML/StyleSections"

QtObject {

    readonly property MainWindowStyleSection window: MainWindowStyleSection {}

    readonly property ControlsStyleSection controls: ControlsStyleSection {}
}
