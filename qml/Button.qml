import QtQuick 2.0

Rectangle {
    id: root

    property alias text: buttonText.text

    signal clicked

    width: 100
    height: 100

    border {
        color: "black"
        width: 1
    }

    Rectangle {
        anchors.fill: parent

        color: "#33000000"

        visible: mouseArea.pressed
    }

    Text {
        id: buttonText

        anchors.centerIn: parent

        elide: Text.ElideRight
    }

    MouseArea {
        id: mouseArea

        anchors.fill: parent

        onClicked: root.clicked()
    }
}
