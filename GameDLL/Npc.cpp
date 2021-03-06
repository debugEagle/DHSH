#include "stdafx.h"
#include "Npc.h"
#include <MyTools/Log.h>
#include <MyTools/TimeTick.h>
#include <MyTools/Character.h>
#include "ExcuteAction.h"
#include "GameCALL.h"
#include "GameUiExtend.h"
#include "PlayerMove.h"
#include "PersonAttribute.h"

#define _SELF L"Npc.cpp"
CNpc::CNpc() : CPlayer(NULL)
{

}

CNpc::CNpc(_In_ DWORD dwNodeBase) : CPlayer(dwNodeBase)
{

}

BOOL CNpc::OpenNpcDlg() CONST
{
	if (GetDis() > 15)
	{
		LOG_CF_E(L"与Npc[%s] 距离[%.2f]过远, 打开对话失败!", GetName().c_str(), GetDis());
		return FALSE;
	}

	MyTools::CTimeTick TimeTick;
	while (GameRun && !MyTools::InvokeClassPtr<CGameUiExtend>()->IsShowNpcDlg())
	{
		if (TimeTick.GetSpentTime(MyTools::CTimeTick::em_TimeTick::em_TimeTick_Second) > 10)
		{
			LOG_CF_E(L"与Npc[%s] 距离[%.2f], 打开对话失败! 超时10秒", GetName().c_str(), GetDis());
			return FALSE;
		}

		LOG_CF_D(L"打开Npc对话[%s]", GetName().c_str());
		MyTools::InvokeClassPtr<CExcuteAction>()->PushPtrToMainThread([this]
		{
			MyTools::InvokeClassPtr<CGameCALL>()->OpenNpc(GetId());
		});
		GameSleep(1000);
	}
	
	return TRUE;
}

BOOL CNpc::ClickOption(_In_ CONST std::wstring& wsOptionText, _In_ CONST std::wstring& wsNewDlg) CONST
{
	return ClickOption_By_Condition(wsOptionText, [wsNewDlg] { return MyTools::InvokeClassPtr<CGameUiExtend>()->IsShowDlg(wsNewDlg); });
}


BOOL CNpc::ClickOption_Once(_In_ CONST std::wstring& wsOptionText) CONST
{
	BOOL bClick = FALSE;
	return ClickOption_By_Condition(wsOptionText, [&bClick]
	{ 
		bClick = !bClick;
		return !bClick;
	});
}

BOOL CNpc::CLickOption_DisableDlg(_In_ CONST std::wstring& wsOptionText, _In_ CONST std::wstring& wsDlg) CONST
{
	return ClickOption_By_Condition(wsOptionText, [wsDlg] { return !MyTools::InvokeClassPtr<CGameUiExtend>()->IsShowDlg(wsDlg); });
}

BOOL CNpc::ClickOption_By_Condition(_In_ CONST std::wstring& wsOptionText, _In_ std::function<BOOL(VOID)> fnExitPtr) CONST
{
	MyTools::CTimeTick TimeTick;
	while (GameRun && !fnExitPtr())
	{
		if (TimeTick.GetSpentTime(MyTools::CTimeTick::em_TimeTick::em_TimeTick_Second) > 10)
		{
			LOG_CF_E(L"与Npc[%s] 距离[%.2f], 点击选项:[%s]! 超时10秒", GetName().c_str(), GetDis(), wsOptionText.c_str());
			return FALSE;
		}

		LOG_CF_D(L"点击Npc选项:[%s]", wsOptionText.c_str());
		MyTools::InvokeClassPtr<CExcuteAction>()->PushPtrToMainThread([this, wsOptionText]
		{
			MyTools::InvokeClassPtr<CGameCALL>()->ClickNpcOption(GetId(), MyTools::CCharacter::UnicodeToASCII(wsOptionText).c_str());
		});
		GameSleep(3 * 1000);
	}
	return fnExitPtr();
}

BOOL CNpc::Collect() CONST
{
	return Collect_By_ActionPtr([this] { return GetNodeBase(); });
}

BOOL CNpc::CollectFurniture() CONST
{
	return Collect_By_ActionPtr([this] { return GetId(); });
}

BOOL CNpc::Collect_By_ActionPtr(_In_ std::function<DWORD(VOID)> ActionPtr) CONST
{
	if (!MyTools::InvokeClassPtr<CPlayerMove>()->MoveToPoint(GetPoint()))
	{
		LOG_CF_E(L"MoveToPoint Faild! Collect Faild!");
		return FALSE;
	}

	LOG_CF_D(L"采集物品[%s]", GetName().c_str());
	MyTools::InvokeClassPtr<CExcuteAction>()->PushPtrToMainThread([ActionPtr]
	{
		MyTools::InvokeClassPtr<CGameCALL>()->CollectItem(ActionPtr());
	});

	GameSleep(2 * 1000);
	LOG_CF_D(L"等待采集完毕!");

	MyTools::CTimeTick TimeTick;
	DWORD dwPetPhysicalStrengthValue = MyTools::InvokeClassPtr<CPersonAttribute>()->GetPetPhysicalStrength();
	while (GameRun && (MyTools::InvokeClassPtr<CPersonAttribute>()->IsCollecting() && MyTools::InvokeClassPtr<CPersonAttribute>()->GetPetPhysicalStrength() >= 10))
	{
		GameSleep(1000);
		if (TimeTick.GetSpentTime(MyTools::CTimeTick::em_TimeTick::em_TimeTick_Second) >= 30)
		{
			if (dwPetPhysicalStrengthValue == MyTools::InvokeClassPtr<CPersonAttribute>()->GetPetPhysicalStrength())
			{
				LOG_CF_E(L"30秒之内体力没变化……重新开始采集~");
				break;
			}
			dwPetPhysicalStrengthValue = MyTools::InvokeClassPtr<CPersonAttribute>()->GetPetPhysicalStrength();
			TimeTick.Reset();
		}
	}

	LOG_CF_D(L"采集完毕!");
	return TRUE;
}

