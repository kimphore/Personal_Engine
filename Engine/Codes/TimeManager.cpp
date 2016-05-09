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
	TIMEMAP::iterator iter = find_if(m_mapTimer.begin(), m_mapTimer.end(), CTagFinder(pszKey));

	if (iter == m_mapTimer.end())
		return NULL;

	return iter->second;
}

HRESULT Engine::CTimeManager::AddTimer(const TCHAR* pszKey, _int iFrameLimit)
{
	CTimer* pTimer = FindTimer(pszKey);

	if (pTimer == NULL)
	{
		pTimer = CTimer::Create(iFrameLimit);

		if (pTimer == NULL)
		{
			MSGBOX(L"Timer Create Failed.");

			return E_FAIL;
		}
	}

	//타이머 생성했고,
	m_mapTimer.insert(TIMEMAP::value_type(pszKey, pTimer));

	return S_OK;
}

void Engine::CTimeManager::SetFrameLimit(const TCHAR* pszKey, _int iFrameLimit)
{
	CTimer* pTimer = FindTimer(pszKey);

	if (pTimer == NULL)
		return;

	pTimer->SetFrameLimit(iFrameLimit);
}

void Engine::CTimeManager::Update(const TCHAR* pszKey)
{
	CTimer* pTimer = FindTimer(pszKey);

	if (pTimer == NULL)
		return;

	pTimer->Update();
}

_bool Engine::CTimeManager::UpdateFrame(const TCHAR* pszKey)
{
	CTimer* pTimer = FindTimer(pszKey);

	if (pTimer == NULL)
		return false;

	return pTimer->UpdateFrame();
}

const _float Engine::CTimeManager::GetTimeDelta(const TCHAR* pszKey)
{
	CTimer* pTimer = FindTimer(pszKey);

	if (pTimer == NULL)
		return 0.f;

	return pTimer->GetTimeDelta();
}

void Engine::CTimeManager::ReleaseTimer(const TCHAR* pszKey)
{
	TIMEMAP::iterator iter = find_if(m_mapTimer.begin(), m_mapTimer.end(), Engine::CTagFinder(pszKey));

	if (iter == m_mapTimer.end())
		return;

	m_mapTimer.erase(iter);
}

