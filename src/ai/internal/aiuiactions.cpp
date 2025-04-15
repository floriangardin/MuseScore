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
#include "aiuiactions.h"

#include "ui/view/iconcodes.h"
#include "context/uicontext.h"
#include "context/shortcutcontext.h"
#include "types/translatablestring.h"

using namespace mu::ai;
using namespace muse;
using namespace muse::ui;
using namespace muse::actions;
using namespace muse::async;
using namespace kors::async;

AiUiActions::AiUiActions(std::shared_ptr<AiController> controller)
    : m_controller(std::move(controller))
{
}

const UiActionList AiUiActions::m_mainActions = {
    // UiAction("play",
    //          mu::context::UiCtxProjectOpened,
    //          mu::context::CTX_NOTATION_FOCUSED,
    //          TranslatableString("action", "Play"),
    //          TranslatableString("action", "Play"),
    //          IconCode::Code::PLAY
    //          ),
    
};

void AiUiActions::init()
{
    // Error: Undeclared identifier 'runAsync' and Invalid range expression
    // Fix: Commenting out this block. Channel iteration/listening logic needs review.
    /*
    kors::async::runAsync([this] {
        for (auto&& code : m_controller->actionCheckedChanged()) {
            m_actionCheckedChanged.send(code);
        }
    });
    kors::async::runAsync([this] {
        for (auto&& code : m_controller->actionEnabledChanged()) {
            m_actionEnabledChanged.send(code);
        }
    });
    */
}


const UiActionList& AiUiActions::actionsList() const
{
    static UiActionList alist;
    if (alist.empty()) {
    }
    return alist;
}

bool AiUiActions::actionEnabled(const UiAction& /*act*/) const
{
    // TODO: Implement actual logic based on 'act'
    return true;
}

bool AiUiActions::actionChecked(const UiAction& act) const
{
    return m_controller->actionChecked(act.code);
}

muse::async::Channel<muse::actions::ActionCodeList> AiUiActions::actionEnabledChanged() const
{
    return m_actionEnabledChanged;
}

muse::async::Channel<muse::actions::ActionCodeList> AiUiActions::actionCheckedChanged() const
{
    return m_actionCheckedChanged;
}


