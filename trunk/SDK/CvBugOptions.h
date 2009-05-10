#pragma once

/**********************************************************************

File:		CvBugOptions.h
Author:		EmperorFool
Created:	2009-01-21

Calls out to the BugOptions Python module to check user options.

		Copyright (c) 2009 The BUG Mod. All rights reserved.

OPTIONS:

	Unofficial Patch

		- Collateral Damage Limit - Unit Hover - setUnitHelp(unit)
		- Collateral Damage Limit - Unit Hover Civilopedia/Build - setBasicUnitHelp(type)
		- Replaced by UB - Building Hover - setBuildingHelp(type)

**********************************************************************/

#ifndef BUG_OPTIONS_H
#define BUG_OPTIONS_H

// Must use existing module because the DLL cannot see new modules in CustomAssets
#define PYBugOptionsModule PYCivModule

void logMsg(const char* format, ...);

bool isBug();

bool getDefineBOOL(const char* xmlKey, bool bDefault = false);
int getDefineINT(const char* xmlKey, int iDefault = 0);

bool getBugOptionBOOL(const char* id, bool bDefault = true, const char* xmlKey = NULL);
int getBugOptionINT(const char* id, int iDefault = 0, const char* xmlKey = NULL);

#endif
