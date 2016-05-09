#include "Timer.h"

USING(Engine);

Engine::CTimer::CTimer(_uint iFrameLimit)
	: m_fTimeDelta(0.f)
	, m_fFrameTick(0.f)
	, m_fAccumTime(0.f)
	, m_bStopped(false)
	, m_iBaseTime(0)
	, m_iPausedTime(0)
	, m_iStopTime(0)
	, m_iPrevTime(0)
	, m_iCurrTime(0)
{
	SetFrameLimit(iFrameLimit);
}

Engine::CTimer::~CTimer()
{

}

CTimer* Engine::CTimer::Create(_uint iFrameLimit)
{
	CTimer* pTimer = new CTimer(iFrameLimit);

	if (FAILED(pTimer->Initialize()))
	{
		if(Engine::SafeRelease(pTimer))
			MSGBOX(L"Failed Initialize Timer Class.");
	}

	return pTimer;
}


_ulong Engine::CTimer::Release(void)
{
	_ulong dwRefCnt = Engine::CBase::Release();

	if (dwRefCnt == 0)
	{
		delete this;
	}

	return dwRefCnt;
}


HRESULT Engine::CTimer::Initialize(void)
{
	QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&m_iCpuTick));
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&m_iBaseTime));
	m_iPausedTime	= m_iBaseTime;
	m_iStopTime		= m_iBaseTime;
	m_iPrevTime		= m_iBaseTime;
	m_iCurrTime		= m_iBaseTime;
	m_bStopped		= false;
	
	return S_OK;
}

void Engine::CTimer::Update(void)
{
	if (m_bStopped == true)
	{
		m_fTimeDelta = 0.f;
		return;
	}

	//int64¶û LARGET_INTEGERÀÇ LONGONGÀÌ¶û ´ëÀÀ.
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&m_iCurrTime));
	
	m_fTimeDelta = (_float)(m_iCurrTime - m_iPrevTime) / (_float)m_iCpuTick;

	m_fAccumTime += m_fTimeDelta;
	m_iPrevTime = m_iCurrTime;

	if (m_fTimeDelta < 0.f)
		m_fTimeDelta = 0.f;
}

_bool Engine::CTimer::UpdateFrame(void)
{
	if (m_fFrameTick < m_fAccumTime)
	{
		m_fAccumTime = 0.f;
		return true;
	}

	return false;
}

void Engine::CTimer::Stop(void)
{
	if (!m_bStopped)
	{
		m_bStopped = true;
		QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&m_iStopTime));
	}
}

void Engine::CTimer::Start(void)
{
	__int64 iStartTime;
	QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&iStartTime));

	if (m_bStopped)
	{
		m_iPausedTime += (iStartTime - m_iStopTime);

		m_iPrevTime = iStartTime;
		m_iStopTime = 0;
		m_bStopped	= false;
	}

}