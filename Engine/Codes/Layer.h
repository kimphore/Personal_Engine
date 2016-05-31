#ifndef Layer_h__
#define Layer_h__

#include "engine_include.h"
#include "Base.h"
/*!
 * \file Layer.h
 * \date 2016/05/26 13:28
 *
 * \author Phore
 * Contact: user@company.com
 *
 * \brief Layer클래스.
		  Scene에 물려있는 구조로써, 오브젝트 리스트를 가진다.
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)

class CGameObject;
class ENGINE_DLL CLayer :public Engine::CBase
{
private:
	explicit CLayer(void);
	~CLayer();

public:
	static CLayer* Create(void);
public:
	list<CGameObject*>* FindObjList(const TCHAR* pszKey);
	
public:
	_int Update(const float& fTimeDelta);
	void AddObject(const TCHAR* pszKey, CGameObject* pObject);
	void ReleaseList(const TCHAR* pszKey);
	_ulong Release(void);

private:
	typedef map<const TCHAR*, list<CGameObject*>> OBJMAP;

private:
	OBJMAP m_mapObject;

};

END

#endif // Layer_h__
