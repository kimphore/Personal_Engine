#include "TimeManager.h"
#include "Timer.h"

USING(Engine)

IMPLEMENT_SINGLETON(CTimeManager)

Engine::CTimeManager::CTimeManager(void)
{

}

Engine::CTimeManager::~CTimeManager()
{

}

CTimer* Engine::CTimeManager::FindTimer(const TCHAR* pszKey)
{

}

HRESULT Engine::CTimeManager::AddTimer(const TCHAR* pszKey, _int iFrameLimit)
{

}

void Engine::CTimeManager::SetFrameLimit(const TCHAR* pszKey, _int iFrameLimit)
{

}

void Engine::CTimeManager::Update(const TCHAR* pszKey)
{

}

_bool Engine::CTimeManager::UpdateFrame(const TCHAR* pszKey)
{

}

_float Engine::CTimeManager::GetTimeDelta(const TCHAR* pszKey)
{

}

void Engine::CTimeManager::ReleaseTimer(const TCHAR* pszKey)
{

}

