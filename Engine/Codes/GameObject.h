#ifndef GameObject_h__
#define GameObject_h__

#include "engine_include.h"
#include "Base.h"

/*!
 * \file GameObject.h
 * \date 2016/05/12 10:45
 *
 * \author topkpr
 * Contact: user@company.com
 *
 * \brief 게임의 근간이 되는 게임 오브젝트 슈퍼클래스.
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)

class CComponent;
class ENGINE_DLL CGameObject : public Engine::CBase
{
private:
	explicit CGameObject();
	virtual ~CGameObject();

public:
	//Initialize는 하위 오브젝트마다 다 다르므로 ㄴㄴ;
	virtual _ulong	Update(const _float fTimeDelta);
	virtual void	Render(void) {};
	virtual HRESULT	SetComponent(void);
	_ulong Release(void);

public://Get,Set
	const CComponent* GetComponent(const TCHAR* pszKey);
private:
	typedef map<const TCHAR*, Engine::CComponent> COMPOMAP;
	COMPOMAP m_mapComponent;
private:
	ID3D11Device*	m_pGraphicDevice;
	_ulong			m_iObjectID;
	
};

END

#endif // GameObject_h__
