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
        
        onRequestInProgress: function(inProgress) {
            loadingIndicator.running = inProgress
            sendButton.enabled = !inProgress
            inputField.enabled = !inProgress
        }
        
        onResponseReceived: function(response) {
            responseArea.text = response
        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10 // Add some margins

        Text {
            text: qsTr("Enter the path to a MusicXML file:")
            Layout.fillWidth: true
        }

        TextField {
            id: inputField
            Layout.fillWidth: true
            placeholderText: qsTr("Path to MusicXML file...")
        }

        BusyIndicator {
            id: loadingIndicator
            running: false
            Layout.alignment: Qt.AlignHCenter
            visible: running
        }

        Text {
            id: responseArea
            Layout.fillWidth: true
            Layout.fillHeight: true
            wrapMode: Text.WordWrap
            text: qsTr("Status will appear here...")
        }

        RowLayout {
            Layout.fillWidth: true
            
            Item { Layout.fillWidth: true } // Spacer
            
            FlatButton {
                id: sendButton
                accentButton: true
                text: qsTr("Load MusicXML")
                onClicked: {
                    responseArea.text = qsTr("Loading...")
                    aiPanelModel.sendPrompt(inputField.text) // Call the C++ model
                }
            }
        }
    }
}