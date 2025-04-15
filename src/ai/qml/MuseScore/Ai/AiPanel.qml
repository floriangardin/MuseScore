import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Muse.Ui 1.0
import Muse.UiComponents 1.0 // Import styled components
import MuseScore.Ai 1.0 // Import our AiModel

Item {
    id: root

    property NavigationSection navigationSection
    property int contentNavigationPanelOrderStart

    AiPanelModel {
        id: aiPanelModel
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10 // Add some margins

        TextField {
            id: inputField
            Layout.fillWidth: true
            placeholderText: qsTr("Enter your prompt here...")
        }

        Text {
            id: responseArea
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: qsTr("AI response...")
        }

        FlatButton {
            id: sendButton
            accentButton: true
            Layout.alignment: Qt.AlignRight // Align button to the right
            text: qsTr("Send")
            onClicked: {
                aiPanelModel.sendPrompt(inputField.text) // Call the C++ model
                inputField.text = "" // Clear the input field
            }
        }
    }
}