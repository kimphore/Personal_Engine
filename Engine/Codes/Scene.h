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
 * \brief Scene�� SuperClass.
		  �� ���� ���ٰǾ���, OBJECT����Ʈ�����
		  �⺻������ ������ �־�� �� �͵��� ������ ����.
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
	//�ɼ�����?

private:
	ID3D11Device* m_pGraphicDevice;
	
	
};


END

#endif // Scene_h__
