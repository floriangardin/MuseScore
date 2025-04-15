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
#include "aimodule.h"

#include <QQmlEngine>

#include "modularity/ioc.h"
#include "ui/iuiengine.h"

#include "ui/iuiactionsregister.h"
#include "ui/iinteractiveuriregister.h"

#include "internal/aicontroller.h"
#include "internal/aiuiactions.h"
#include "internal/aiconfiguration.h"
#include "view/aipanelmodel.h"

using namespace mu::ai;
using namespace muse;
using namespace muse::modularity;
using namespace muse::ui;
using namespace muse::actions;

AiModule::~AiModule() = default;

static void ai_init_qrc()
{
    Q_INIT_RESOURCE(ai);
}

std::string AiModule::moduleName() const
{
    return "ai";
}

void AiModule::registerExports()
{
    m_configuration = std::make_shared<AiConfiguration>();
    m_aiController = std::make_shared<AiController>();
    m_aiUiActions = std::make_shared<AiUiActions>(m_aiController);
    m_aiPanelModel = std::make_shared<AiPanelModel>();

    ioc()->registerExport<IAiController>(moduleName(), m_aiController);
    ioc()->registerExport<IAiConfiguration>(moduleName(), m_configuration);
}

void AiModule::resolveImports()
{
    auto ar = ioc()->resolve<IUiActionsRegister>(moduleName());
    if (ar) {
        ar->reg(m_aiUiActions);
    }
}

void AiModule::registerResources()
{
    ai_init_qrc();
}

void AiModule::registerUiTypes()
{
    ioc()->resolve<IUiEngine>(moduleName())->addSourceImportPath(ai_QML_IMPORT);
    qmlRegisterType<AiPanelModel>("MuseScore.Ai", 1, 0, "AiPanelModel");
}

void AiModule::onInit(const IApplication::RunMode& mode)
{
    m_configuration->init();
    m_aiController->init();
    m_aiUiActions->init();
}

void AiModule::onAllInited(const IApplication::RunMode& mode)
{

}
