#ifndef Renderer_h__
#define Renderer_h__

#include "engine_include.h"
#include "GameObject.h"//���� ������Ʈ�� �����Լ��� ���⼭ ȣ����.

/*!
 * \file Renderer.h
 * \date 2016/05/12 13:15
 *
 * \author Phore
 * Contact: user@company.com
 *
 * \brief ������ �ھ �Ǵ� Ŭ����.
		  ������Ʈ ������ ������ �̷�� ���� �κ�.
		  ���۵� ������ ���̽�..���Ҳ��ϱ�..
		  �����׷쵵 ������, ����Ÿ�ٺ��ε� ������.
		  ��ó���� ��.. �������ϰ���
		  �ɼǿ� �ΰ��Ѱ�?
		  �̱��� ����;
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

private://Device ���� �ʿ��Ѱ�
	ID3D11Device* m_pGraphicDevice;
	ID3D11DeviceContext* m_pDeviceContext;

};

END

#endif // Renderer_h__
