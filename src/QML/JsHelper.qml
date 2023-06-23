pragma Singleton

import QtQuick 2.15

QtObject {

    function getCopy(value) {
        return JSON.parse(JSON.stringify(value))
    }

    function equals(A, B, Epsilon) {
        Epsilon = Epsilon || 0.000001

        var equality = 0

        if ((A - B < Epsilon) && (Math.abs(A - B) > Epsilon))
            equality = -1

        if ((A - B > Epsilon) && (Math.abs(A - B) > Epsilon))
            equality = 1

        return equality
    }
}
