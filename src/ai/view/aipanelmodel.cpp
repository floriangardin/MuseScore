/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-Studio-CLA-applies
 *
 * MuseScore Studio
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore Limited
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "aipanelmodel.h"

#include "translation.h"

#include <QApplication>
#include <QClipboard>
#include <QUrl>
#include <QFile>
#include <QBuffer>

#include "engraving/dom/masterscore.h"
#include "engraving/compat/scoreaccess.h"
#include "project/types/projecttypes.h"
#include "actions/actiontypes.h"
#include "log.h"

using namespace mu::ai;

AiPanelModel::AiPanelModel(QObject* parent)
    : QObject(parent), muse::Injectable(muse::iocCtxForQmlObject(this))
{
}

void AiPanelModel::sendPrompt(const QString& prompt)
{
    // For now, the prompt is expected to be a file path to a MusicXML file
    // In a real implementation, this would send text to an AI service
    
    // Signal that we're starting a request
    emit requestInProgress(true);
    
    // Process the file path directly
    mockAiApiCall(prompt);
}

void AiPanelModel::mockAiApiCall(const QString& filePath)
{
    // Read the file
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        emit requestInProgress(false);
        emit responseReceived(QString("Error: Failed to open file: %1").arg(filePath));
        return;
    }
    
    // Read the file contents
    QByteArray fileData = file.readAll();
    file.close();
    
    if (fileData.isEmpty()) {
        emit requestInProgress(false);
        emit responseReceived(QString("Error: File is empty: %1").arg(filePath));
        return;
    }
    
    // Load the MusicXML data directly
    loadMusicXMLToScore(fileData);
}

void AiPanelModel::loadMusicXMLToScore(const QByteArray& musicXmlData)
{
    try {
        // Write the MusicXML data to a temporary file
        QString tempFilePath = muse::io::path_t(globalConfiguration.get()->appDataPath() + "/temp_ai_musicxml.musicxml").toQString();
        QFile tempFile(tempFilePath);
        if (!tempFile.open(QIODevice::WriteOnly)) {
            throw std::runtime_error("Failed to create temporary file");
        }
        tempFile.write(musicXmlData);
        tempFile.close();
        
        // Use action dispatcher to open the project and replace any existing one
        dispatcher()->dispatch("replace-current-project", muse::actions::ActionData::make_arg2<QUrl, QString>(
            QUrl::fromLocalFile(tempFilePath), 
            "AI Generated Score"
        ));
        
        emit requestInProgress(false);
        emit responseReceived("MusicXML successfully loaded");
    } catch (const std::exception& e) {
        LOGE() << "Error loading MusicXML: " << e.what();
        emit requestInProgress(false);
        emit responseReceived(QString("Error: %1").arg(e.what()));
    }
}




