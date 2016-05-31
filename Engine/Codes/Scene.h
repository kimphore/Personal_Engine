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

		  Scene에는 내부적으로 Layer_map을 가진다.
		  그 안에 GameObject들이 들어가서 돌아감 ㅇㅇ;
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)

class CGameObject;
class CLayer;
class ENGINE_DLL CScene :public Engine::CBase
{
protected:
	explicit CScene();
	~CScene(void);
public:
	HRESULT Initialize(ID3D11Device* pGraphicDevice);
	_ulong Update(const _float& fTimeDelta);
	void Render(void);
	_ulong Release(void);

public://Layer조작관련
	CLayer* GetLayer(const TCHAR* pszKey);
	HRESULT AddLayer(const TCHAR* pszKey);
	list<CGameObject*>* GetObjectList(const TCHAR* pszMapKey, const TCHAR* pszListKey);
	HRESULT AddObject(const TCHAR* pszMapKey, const TCHAR* pszListKey, CGameObject* pObject);

protected:
	typedef map<const TCHAR*, CLayer*> LAYERMAP;
	LAYERMAP m_mapLayer;
	ID3D11Device* m_pGraphicDevice;
	
	
};


END

#endif // Scene_h__
