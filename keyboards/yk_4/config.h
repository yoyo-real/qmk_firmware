// Copyright 2024 yoyo
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Mirror master side matrix to slave so RGB Matrix reactive effects
// (multisplash etc.) fire on both halves regardless of which side's key
// was pressed. Recommended by QMK docs alongside RGB_MATRIX_SPLIT.
#define SPLIT_TRANSPORT_MIRROR
