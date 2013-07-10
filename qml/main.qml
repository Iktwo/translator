import QtQuick 2.0

Rectangle {
    id: root

    width: 360
    height: 360

    Text {
        text: qsTr("Hello World") + translator.tr
        anchors.centerIn: parent
    }

    Flow {
        anchors.fill: parent

        Button {
            id: frenchButton

            text: qsTr("French") + translator.tr

            onClicked: {
                translator.translate("FR")
            }
        }

        Button {
            id: englishButton

            text: qsTr("English") + translator.tr

            onClicked: {
                translator.translate("DEFAULT")
            }
        }

        Button {
            id: spanishButton

            text: qsTr("Spanish") + translator.tr

            onClicked: {
                translator.translate("ES")
            }
        }
    }
}
