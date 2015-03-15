////////////////////////////////////////////////////////////////////////////////
//
// $LastChangedBy: jswigart@gmail.com $
// $LastChangedDate: 2013-03-07 21:15:21 -0600 (Thu, 07 Mar 2013) $
// $LastChangedRevision: 837 $
//
// Title: BotExports
//		In order for the game to call functions from the bot, we must export
//		the functions to the game itself and allow it to call them.
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __BOTEXPORTS_H__
#define __BOTEXPORTS_H__

#include "Functions_Bot.h"
#include "Omni-Bot_Types.h"
#include "Omni-Bot_Events.h"
#include "IEngineInterface.h"

//////////////////////////////////////////////////////////////////////////
// Export the function on platforms that require it.
#ifdef WIN32
#define OMNIBOT_API __declspec(dllexport)
#else
#define OMNIBOT_API
#endif

// Typedef for the only exported bot function.
typedef omnibot_error (*pfnGetFunctionsFromDLL)(Bot_EngineFuncs *_pBotFuncs, int _size);

// note: Export Functions with C Linkage
//	Export with C Linkage so the game interface can acccess it easier.
//	This gets rid of name mangling
//	Wrapped in #ifdef because the game SDK might be in pure C
#ifdef __cplusplus
extern "C"
{
#endif
	// function: ExportBotFunctionsFromDLL
	//		Allow the bot dll to fill in a struct of bot functions the interface
	//		can then call.
	OMNIBOT_API omnibot_error ExportBotFunctionsFromDLL(Bot_EngineFuncs *_pBotFuncs, int _size);

	OMNIBOT_API void RenderOpenGL();
#ifdef __cplusplus
}
#endif

//////////////////////////////////////////////////////////////////////////
// Interfaces

extern Bot_EngineFuncs	gBotFunctions;
extern IEngineInterface		*gGameFunctions;

//////////////////////////////////////////////////////////////////////////
// Utility Function
extern "C" const char *OB_VA(const char* _msg, ...);
//////////////////////////////////////////////////////////////////////////

omnibot_error Omnibot_LoadLibrary(int version, const char *lib, const char *path);
void Omnibot_FreeLibrary();
bool IsOmnibotLoaded();
const char *Omnibot_ErrorString(omnibot_error err);
const char *Omnibot_GetLibraryPath();
const char *Omnibot_FixPath(const char *_path);
#endif
