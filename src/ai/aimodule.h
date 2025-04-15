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
#ifndef MU_Ai_AiMODULE_H
#define MU_Ai_AiMODULE_H

#include <memory>

#include "modularity/imodulesetup.h"

namespace mu::ai {
class AiConfiguration;
class AiController;
class AiUiActions;
class AiPanelModel;
class AiModule : public muse::modularity::IModuleSetup
{
public:
    virtual ~AiModule() override;

    std::string moduleName() const override;
    void registerExports() override;
    void resolveImports() override;
    void registerResources() override;
    void registerUiTypes() override;
    void onInit(const muse::IApplication::RunMode& mode) override;
    void onAllInited(const muse::IApplication::RunMode& mode) override;

private:
    std::shared_ptr<AiConfiguration> m_configuration;
    std::shared_ptr<AiController> m_aiController;
    std::shared_ptr<AiUiActions> m_aiUiActions;
    std::shared_ptr<AiPanelModel> m_aiPanelModel;
};
}

#endif // MU_Ai_AiMODULE_H