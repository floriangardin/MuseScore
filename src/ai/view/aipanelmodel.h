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
#ifndef MU_AI_AIPANELMODEL_H
#define MU_AI_AIPANELMODEL_H

#include <QObject>

#include "modularity/ioc.h"
#include "iaiconfiguration.h"
#include "global/iglobalconfiguration.h"
#include "global/iapplication.h"
#include "context/iglobalcontext.h"
#include "notation/inotationcreator.h"
#include "project/internal/notationreadersregister.h"
#include "async/asyncable.h"
#include "notation/inotation.h"
#include "project/inotationproject.h"
#include "project/iprojectcreator.h"

class QUrl;

namespace mu::ai {
class AiPanelModel : public QObject, public muse::Injectable
{
    Q_OBJECT

    Inject<IAiConfiguration> configuration = { this };
    Inject<muse::IGlobalConfiguration> globalConfiguration = { this };
    Inject<muse::IApplication> application = { this };
    Inject<context::IGlobalContext> globalContext = { this };
    Inject<notation::INotationCreator> notationCreator = { this };
    Inject<project::INotationReadersRegister> notationReaders = { this };
    Inject<project::IProjectCreator> projectCreator = { this };

public:
    explicit AiPanelModel(QObject* parent = nullptr);

    Q_INVOKABLE void sendPrompt(const QString& prompt);

signals:
    void requestInProgress(bool inProgress);
    void responseReceived(const QString& response);

private:
    // Mock AI API call that returns MusicXML data
    void mockAiApiCall(const QString& filePath);
    
    // Load MusicXML data and replace current score
    void loadMusicXMLToScore(const QByteArray& musicXmlData);
    
};
}

#endif // MU_AI_AIPANELMODEL_H
