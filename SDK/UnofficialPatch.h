#pragma once

// UnofficialPatch.h -- Extra defines for versioning and custom compilation.

#ifndef CIV4_UNOFFICIAL_PATCH_H
#define CIV4_UNOFFICIAL_PATCH_H

// Currently only controls return value of CvGlobals::isUnofficialPatch()
// Eventually may be used to globally enable/disable all Unofficial Patch changes.
#define _USE_UNOFFICIALPATCH

// This define controls whether jdog5000's AIAutoPlay changes are made.
#define _USE_AIAUTOPLAY

// Version numbers. Note this is an "integer times 100" since floats are prone to roundoff error.
#define UP_PATCH_VERSION (21)

#endif