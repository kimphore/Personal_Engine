#include "TimeManager.h"

/*
Timer 관련 Exports 함수
*/

void Engine::Add_Timer(const TCHAR* pszKey, int iFrameLimit)
{
	Engine::CTimeManager::GetInstance()->AddTimer(pszKey, iFrameLimit);
}
void Engine::SetFrameLimit(const TCHAR* pszKey, int iFrameLimit)
{
	Engine::CTimeManager::GetInstance()->SetFrameLimit(pszKey, iFrameLimit);
}
void Engine::Timer_Update(const TCHAR* pszKey)
{
	Engine::CTimeManager::GetInstance()->Update(pszKey);
}
bool Engine::Timer_FrameUpdate(const TCHAR* pszKey)
{
	return Engine::CTimeManager::GetInstance()->UpdateFrame(pszKey);
}
const float Engine::GetTimeDelta(const TCHAR* pszKey)
{
	return Engine::CTimeManager::GetInstance()->GetTimeDelta(pszKey);
}
void Engine::ReleaseTimer(const TCHAR* pszKey)
{
	Engine::CTimeManager::GetInstance()->ReleaseTimer(pszKey);
}

void Engine::ReleaseEngine(void)
{
	Engine::CTimeManager::GetInstance()->DestroyInstance();
}