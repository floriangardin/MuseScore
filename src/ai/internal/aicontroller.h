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
#ifndef MU_AI_AICONTROLLER_H
#define MU_AI_AICONTROLLER_H

#include "modularity/ioc.h"
#include "async/asyncable.h"
#include "actions/iactionsdispatcher.h"
#include "actions/actionable.h"
#include "context/iglobalcontext.h"
#include "iinteractive.h"

#include "../iaicontroller.h"
#include "../iaiconfiguration.h"

namespace mu::ai {
class AiController : public IAiController, public muse::actions::Actionable, public muse::async::Asyncable
{
    INJECT_STATIC(muse::actions::IActionsDispatcher, dispatcher)
    INJECT_STATIC(context::IGlobalContext, globalContext)
    INJECT_STATIC(IAiConfiguration, configuration)
    INJECT_STATIC(muse::IInteractive, interactive)

public:
    void init();

    void reset() override;

    bool actionChecked(const muse::actions::ActionCode& actionCode) const override;
    const muse::async::Channel<muse::actions::ActionCode>& actionCheckedChanged() const override;


private:
    muse::async::Channel<muse::actions::ActionCode> m_actionCheckedChanged;
};
}

#endif // MU_AI_AICONTROLLER_H
