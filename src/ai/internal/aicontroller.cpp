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
#include "aicontroller.h"

#include "aitypes.h"



#include "containers.h"
#include "defer.h"
#include "log.h"

using namespace muse;
using namespace muse::actions;
using namespace muse::async;
using namespace muse::audio;
using namespace muse::midi;
using namespace mu::engraving;
using namespace mu::notation;
using namespace mu::ai;

void AiController::init()
{
    
}

void AiController::reset()
{
    // Error: No viable conversion from 'ActionCodeList' to 'const std::string'
    // Fix: Commenting out. The channel expects ActionCode, not ActionCodeList.
    //      The correct action to send on reset needs clarification.
    // m_actionCheckedChanged.send(ActionCodeList());
}

bool AiController::actionChecked(const ActionCode& /*actionCode*/) const
{
    // Minimal implementation: no actions are checked by default
    return false;
}

const Channel<ActionCode>& AiController::actionCheckedChanged() const
{
    return m_actionCheckedChanged;
}



