# SPDX-License-Identifier: GPL-3.0-only
# MuseScore-Studio-CLA-applies
#
# MuseScore Studio
# Music Composition & Notation
#
# Copyright (C) 2021 MuseScore Limited
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

declare_module(ai)

set(MODULE_QRC ai.qrc)
set(MODULE_QML_IMPORT ${CMAKE_CURRENT_LIST_DIR}/qml)

set(MODULE_SRC
    #public
    ${CMAKE_CURRENT_LIST_DIR}/aimodule.cpp
    ${CMAKE_CURRENT_LIST_DIR}/aimodule.h
    ${CMAKE_CURRENT_LIST_DIR}/iaicontroller.h
    ${CMAKE_CURRENT_LIST_DIR}/iaiconfiguration.h
    ${CMAKE_CURRENT_LIST_DIR}/aitypes.h

    #internals
    ${CMAKE_CURRENT_LIST_DIR}/internal/aicontroller.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/aicontroller.h
    ${CMAKE_CURRENT_LIST_DIR}/internal/aiuiactions.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/aiuiactions.h
    ${CMAKE_CURRENT_LIST_DIR}/internal/aiconfiguration.cpp
    ${CMAKE_CURRENT_LIST_DIR}/internal/aiconfiguration.h

    # View
    # ${CMAKE_CURRENT_LIST_DIR}/view/aipanel.cpp
    # ${CMAKE_CURRENT_LIST_DIR}/view/aipanel.h

    )

if (MUE_BUILD_AI_TESTS)
    add_subdirectory(tests)
endif()

setup_module()
