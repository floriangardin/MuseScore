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
#ifndef MU_AI_IAICONTROLLER_H
#define MU_AI_IAICONTROLLER_H

#include "modularity/imoduleinterface.h"
#include "async/notification.h"
#include "async/channel.h"
#include "async/promise.h"
#include "global/progress.h"
#include "notation/inotation.h"
#include "notation/notationtypes.h"
#include "audio/audiotypes.h"
#include "actions/actiontypes.h"

#include "aitypes.h"

namespace mu::ai {
class IAiController : MODULE_EXPORT_INTERFACE
{
    INTERFACE_ID(IAiController);

public:
    virtual void reset() = 0;
    virtual bool actionChecked(const muse::actions::ActionCode& actionCode) const = 0;
    virtual const muse::async::Channel<muse::actions::ActionCode>& actionCheckedChanged() const = 0;
    virtual ~IAiController() = default;

};
}

#endif // MU_AI_IAICONTROLLER_H
