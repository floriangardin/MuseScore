/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2024 MuseScore BVBA and others
 */
import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import Muse.Ui 1.0
import Muse.UiComponents 1.0
import MuseScore.AppShell 1.0

// Basic Panel container
Rectangle {
    id: root

    // Instantiate the C++ model
    AiPromptPanelModel {
        id: model
    }

    // Initially hidden
    visible: false
    // Height can be adjusted as needed
    height: 50
    // Anchored to the bottom, width matches parent (will be set later when integrated)
    anchors.left: parent.left
    anchors.right: parent.right
    // Anchors.bottom will be set relative to the status bar later

    color: ui.theme.panelBackgroundColor // Example color, adjust as needed

    RowLayout {
        anchors.fill: parent
        anchors.margins: 5 // Add some padding

        TextInputArea {
            id: promptInput
            Layout.fillWidth: true
            Layout.fillHeight: true
            hint: qsTr("Enter your AI prompt here...") // Placeholder text
            currentText: "" // Initial text
        }

        FlatButton {
            id: sendButton
            Layout.alignment: Qt.AlignVCenter
            text: qsTr("Send")
            icon: IconCode.SEND // Example icon, find appropriate one later if needed
            buttonType: FlatButton.IconOnly // Or TextOnly, Horizontal
            enabled: model.sendEnabled
            onClicked: {
                model.sendPrompt(promptInput.currentText)
            }
        }
    }
} 