#ifndef Renderer_h__
#define Renderer_h__

#include "engine_include.h"
#include "GameObject.h"//실제 오브젝트의 랜더함수를 여기서 호출함.

/*!
 * \file Renderer.h
 * \date 2016/05/12 13:15
 *
 * \author Phore
 * Contact: user@company.com
 *
 * \brief 랜더의 코어가 되는 클래스.
		  오브젝트 랜더가 실제로 이루어 지는 부분.
		  디퍼드 랜더링 베이스..로할꺼니까..
		  랜더그룹도 나누고, 랜더타겟별로도 나누고.
		  후처리는 뭐.. 언젠간하겠지
		  옵션에 민감한가?
		  싱글톤 ㄴㄴ;
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)

class CScene;
class CGameObject;
class ENGINE_DLL CRenderer
{
private:
	explicit CRenderer(void);
	~CRenderer(void);

public:
	static CRenderer* Create(ID3D11Device** pDevice, ID3D11DeviceContext** ppContext);
	HRESULT Initialize(ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext);
	_ulong	Release(void);
	void	Render(void);
	void	ClearObjectGroup(void);
	//Base on Deffered;
private://Render Type
	void RenderZsort(void);
	void RenderAlpha(void);
public://Setter
	void BindScene(CScene** pScene);
private:
	typedef list<CGameObject*> OBJLIST;
private:
	OBJLIST m_arrRenderGroup[RENDER_END];
	CScene*	m_pCurrentScene;

private://Device 관련 필요한것
	ID3D11Device* m_pGraphicDevice;
	ID3D11DeviceContext* m_pDeviceContext;

};

END

#endif // Renderer_h__
