////////////////////////////////////////////////////////////////////////////////
//
// $LastChangedBy: jswigart@gmail.com $
// $LastChangedDate: 2013-03-07 21:15:21 -0600 (Thu, 07 Mar 2013) $
// $LastChangedRevision: 837 $
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#ifndef __FUNCTIONS_BOT_H__
#define __FUNCTIONS_BOT_H__

#include "Omni-Bot.h"
#include "Omni-Bot_Types.h"
#include "Omni-Bot_Events.h"
#include "MessageHelper.h"
#include "IEngineInterface.h"

// Title: Functions Bot

// typedef: Bot_EngineFuncs
//		This struct defines all the function pointers that the bot will fill in
//		and give to the interface so that the interface can request the entire
//		suite of functions at once from the bot.
struct Bot_EngineFuncs
{
	omnibot_error (*pfnInitialize)(IEngineInterface *_pEngineFuncs, int _version);
	void (*pfnUpdate)();
	void (*pfnShutdown)();
	void (*pfnConsoleCommand)(const Arguments &_args);

	void (*pfnSendTrigger)(const TriggerInfo &_triggerInfo);
	void (*pfnAddBlackboardRecord)(BlackBoard_Key _type, int _posterID, int _targetID, obUserData *_data);

	// events
	void (*pfnSendEvent)(int _dest, const MessageHelper &_message);
	void (*pfnSendGlobalEvent)(const MessageHelper &_message);

	void (*pfnSendEventEx)(GameEntity dest, const int msgId, const void * msgPayload, const size_t msgSize );

	// goals
	void (*pfnAddGoal)(const MapGoalDef &goaldef);
	void (*pfnDeleteGoal)(const char *goalname);
	void (*pfnUpdateEntity)(GameEntity oldent,GameEntity newent);
} ;

//#define DllExport __declspec( dllexport )
//
//class DllExport IBotEngineInterface
//{
//	omnibot_error Initialize(IEngineInterface *_pEngineFuncs, int _version) = 0;
//	void Update() = 0;
//	void Shutdown() = 0;
//	void ConsoleCommand(const Arguments &_args) = 0;
//
//	void SendTrigger(const TriggerInfo &_triggerInfo) = 0;
//	void AddBlackboardRecord(BlackBoard_Key _type, int _posterID, int _targetID, obUserData *_data) = 0;
//
//	void AddGoal(const MapGoalDef &goaldef) = 0;
//	void DeleteGoal(const char *goalname) = 0;
//
//	// New message stuff.
//	void SendEvent(int _dest, const MessageHelper &_message) = 0;
//	void SendGlobalEvent(const MessageHelper &_message) = 0;
//	void UpdateEntity(GameEntity oldent,GameEntity newent) = 0;
//
//};

#endif
