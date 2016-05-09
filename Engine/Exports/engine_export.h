#ifndef Engine_Export_h__
#define Engine_Export_h__

namespace Engine
{
	/*
	Timer 관련 Exports 함수
	*/
	void Add_Timer(const TCHAR* pszKey, int iFrameLimit);
	void SetFrameLimit(const TCHAR* pszKey, int iFrameLimit);
	void Timer_Update(const TCHAR* pszKey);
	bool Timer_FrameUpdate(const TCHAR* pszKey);
	const float GetTimeDelta(const TCHAR* pszKey);
	void ReleaseTimer(const TCHAR* pszKey);


	/*
	Engine 공통 사용 Exports 함수
	*/
	void ReleaseEngine(void);
}

#include "engine_export.inl"


#endif // Engine_Export_h__
