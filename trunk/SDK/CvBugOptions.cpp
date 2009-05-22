/**********************************************************************

File:		CvBugOptions.cpp
Author:		EmperorFool
Created:	2009-01-21

		Copyright (c) 2009 The BUG Mod. All rights reserved.

**********************************************************************/

#include "CvGameCoreDLL.h"
#include "CyArgsList.h"
#include "CvDLLPythonIFaceBase.h"
#include "FVariableSystem.h"

#include "CvBugOptions.h"

bool g_bIsBug = false;
bool g_bInitDone = false;


void logMsg(const char* format, ...)
{
	static char buf[2048];
	_vsnprintf( buf, 2048-4, format, (char*)(&format+1) );
	gDLL->logMsg("bug.log", buf);
}


void bugInit()
{
	if (!g_bInitDone)
	{
		long lResult = 0;

		logMsg("BUG - isBug()");
		if (gDLL->getPythonIFace()->callFunction(PYBugOptionsModule, "isBug", NULL, &lResult))
		{
			logMsg("BUG - got value %ld", lResult);
			g_bIsBug = lResult;
			if (g_bIsBug)
			{
				logMsg("BUG - BUG is present");
			}
		}
		else
		{
			logMsg("BUG - call to isBug() failed; BUG not present");
			g_bIsBug = false;
		}

		g_bInitDone = true;
	}
}

bool isBug()
{
	bugInit();
	return g_bIsBug;
}


bool getDefineBOOL(const char* xmlKey, bool bDefault)
{
	int iResult = 0;
	if (GC.getDefinesVarSystem()->GetValue(xmlKey, iResult))
	{
		return iResult != 0;
	}
	else
	{
		return bDefault;
	}
}

int getDefineINT(const char* xmlKey, int iDefault)
{
	int iResult = 0;
	if (GC.getDefinesVarSystem()->GetValue(xmlKey, iResult))
	{
		return iResult;
	}
	else
	{
		return iDefault;
	}
}


bool getBugOptionBOOL(const char* id, bool bDefault, const char* xmlKey)
{
	if (isBug())
	{
		CyArgsList argsList;
		long lResult = 0;

		argsList.add(id);
		argsList.add(bDefault);

		//logMsg("BUG - getOptionBOOL(%s)", id);
		gDLL->getPythonIFace()->callFunction(PYBugOptionsModule, "getOptionBOOL", argsList.makeFunctionArgs(), &lResult);
		//logMsg("BUG - got value %ld", lResult);

		return lResult != 0;
	}
	else
	{
		CvString tmp;
		if (!xmlKey)
		{
			tmp.append("BUG__");
			tmp.append(id);
			xmlKey = tmp.c_str();
		}
		return getDefineBOOL(xmlKey, bDefault);
	}
}

int getBugOptionINT(const char* id, int iDefault, const char* xmlKey)
{
	if (isBug())
	{
		CyArgsList argsList;
		long lResult = 0;

		argsList.add(id);
		argsList.add(iDefault);

		//logMsg("BUG - getOptionBOOL(%s)", id);
		gDLL->getPythonIFace()->callFunction(PYBugOptionsModule, "getOptionINT", argsList.makeFunctionArgs(), &lResult);
		//logMsg("BUG - got value %ld", lResult);

		return lResult;
	}
	else
	{
		CvString tmp;
		if (!xmlKey)
		{
			tmp.append("BUG__");
			tmp.append(id);
			xmlKey = tmp.c_str();
		}
		return getDefineINT(xmlKey, iDefault);
	}
}