#ifndef Scene_h__
#define Scene_h__

#include "engine_include.h"
#include "Base.h"
/*!
 * \file Scene.h
 * \date 2016/05/10 16:09
 *
 * \author Phore
 * Contact: user@company.com
 *
 * \brief Scene의 SuperClass.
		  뭐 딱히 해줄건없고, OBJECT리스트라던가
		  기본적으로 가지고 있어야 할 것들을 가지고 있음.
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)

class CGameObject;
class ENGINE_DLL CScene :public Engine::CBase
{
protected:
	explicit CScene();
	~CScene(void);
public:
	HRESULT Initialize(ID3D11Device* pGraphicDevice, _ulong dwListCnt);
	_ulong Update(const _float& fTimeDelta);
	void Render(void);
	_ulong Release(void);

protected:
	typedef list<const TCHAR*, CGameObject*> OBJLIST;
	OBJLIST* m_pObjLists;
	_ulong m_dwListCnt;

private://For Render FPS;
	//옵션으로?

private:
	ID3D11Device* m_pGraphicDevice;
	
	
};


END

#endif // Scene_h__
