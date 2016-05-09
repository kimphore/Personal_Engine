#ifndef TimeManager_h__
#define TimeManager_h__

#include "engine_include.h"

/*!
 * \class TimeManager
 *
 * \brief Time Class들 관리.
 *
 * \author topkpr
 * \date 5월 2016
 */

BEGIN(Engine)

class CTimer;
class ENGINE_DLL CTimeManager
{
	DECLARE_SINGLETON(CTimeManager)
private:
	explicit CTimeManager(void);
public:
	~CTimeManager();

private:
	typedef map<const TCHAR*, CTimer*> TIMEMAP;
	TIMEMAP m_mapTimer;

public:
	CTimer* FindTimer(const TCHAR* pszKey);
public:
	HRESULT			AddTimer(const TCHAR* pszKey, _int iFrameLimit);
	void			SetFrameLimit(const TCHAR* pszKey, _int iFrameLimit);
	void			Update(const TCHAR* pszKey);
	_bool			UpdateFrame(const TCHAR* pszKey);
	const _float	GetTimeDelta(const TCHAR* pszKey);
	void			ReleaseTimer(const TCHAR* pszKey);

};

END


#endif // TimeManager_h__
