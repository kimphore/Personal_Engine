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
	static CRenderer* Create(ID3D11Device** pGraphicDevice);
	_ulong	Release(void);
	void	Render(void);
	//Base on Deffered;
public://Setter
	void BindScene(CScene** pScene);
private:
	typedef list<CGameObject*> OBJLIST;
	OBJLIST m_arrRenderGroup[RENDER_END];
	CScene*	m_pCurrentScene;


};

END

#endif // Renderer_h__
