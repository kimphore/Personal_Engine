#ifndef Base_h__
#define Base_h__

#include "engine_include.h"

/*!
 * \class CBase
 *
 * \brief 모든 클래스의 Super Class. CObject같은거.
 *			레퍼런스 포인터?
 *	
 * \author topkpr
 * \date 5월 2016
 */

BEGIN(Engine)

class ENGINE_DLL CBase
{
public:
	explicit CBase(void);
	virtual ~CBase(void);

public:
	void AddRef(void) {
		++m_dwRefCnt;
	}

	virtual _ulong Release(void) {
		return m_dwRefCnt--;
	}

protected:
	_ulong m_dwRefCnt;
};

END
#endif // Base_h__
