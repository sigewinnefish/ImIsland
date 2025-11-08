#pragma once
#include <Windows.h>

struct IslandFunctionOffsets
{
    DWORD GameManagerAwake;
    DWORD MickeyWonderMethod;
    DWORD MickeyWonderMethodPartner;
    DWORD MickeyWonderMethodPartner2;
    DWORD SetLastUid;
    DWORD SetFieldOfView;
    DWORD SetEnableFogRendering;
    DWORD GetTargetFrameRate;
    DWORD SetTargetFrameRate;
    DWORD OpenTeam;
    DWORD OpenTeamPageAccordingly;
    DWORD CheckCanEnter;
    DWORD SetupQuestBanner;
    DWORD FindGameObject;
    DWORD SetActive;
    DWORD EventCameraMove;
    DWORD ShowOneDamageTextEx;
    DWORD SwitchInputDeviceToTouchScreen;
    DWORD MickeyWonderCombineEntryMethod;
    DWORD MickeyWonderCombineEntryMethodPartner;
    DWORD SetupResinList;
    DWORD ResinList;
    DWORD ResinListGetCount;
    DWORD ResinListGetItem;
    DWORD ResinListRemove;
};

struct IslandEnvironment
{
    DWORD Size;
    DWORD State;
    DWORD LastError;
    DWORD Uid;
    IslandFunctionOffsets IslandFunctionOffsets;
    BOOL  EnableSetFieldOfView;
    FLOAT FieldOfView;
    BOOL  FixLowFovScene;
    BOOL  DisableFog;
    BOOL  EnableSetTargetFrameRate;
    DWORD TargetFrameRate;
    BOOL  RemoveOpenTeamProgress;
    BOOL  HideQuestBanner;
    BOOL  DisableEventCameraMove;
    BOOL  DisableShowDamageText;
    BOOL  UsingTouchScreen;
    BOOL  RedirectCombineEntry;
    BOOL  ResinListItemId000106Allowed;
    BOOL  ResinListItemId000201Allowed;
    BOOL  ResinListItemId107009Allowed;
    BOOL  ResinListItemId107012Allowed;
    BOOL  ResinListItemId220007Allowed;
};