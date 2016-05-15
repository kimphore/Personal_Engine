#ifndef Framework_h__
#define Framework_h__

#include "engine_include.h"
#include "Renderer.h"
/*!
 * \file Framework.h
 * \date 2016/05/09 22:49
 *
 * \author topkpr
 * Contact: user@company.com
 *
 * \brief ������ü���� ������ ���ִ� Ŭ����.
			���� ������ �����ְ�,
			�����κа� ��� ������Ʈ���� �� �Ʒ��� ���ư���.
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)

class CScene;
class ENGINE_DLL CFramework
{
	DECLARE_SINGLETON(CFramework)
private:
	explicit CFramework(void);
public:
	~CFramework(void);

public:
	template<typename T>
	HRESULT ChangeScene(T& Functor);
	
private:
	void Initialize(ID3D11Device** pDevice);
	void Update(const _float& fTimeDelta);
	void Render(void);
	void Release(void);

public://�ܺο��� ����� ���� �Լ���
	/*
		�ܺ� <-----Framework------->Scene,Renderer ����
	*/
	const CXMMATRIX& GetMatrix(MATRIX_OPTION eOption);
	const void SetMatrix(MATRIX_OPTION eOption, CXMMATRIX rMat);

private:
	ID3D11Device*	m_pGraphicDevice;
	CScene*			m_pCurrentScene;
	CRenderer*		m_pRenderer;

private://Framework�ν� �����ؾ� �� �κ�. ��, ���������, �ɼǰ� ��
	XMFLOAT4X4					m_matView;
	XMFLOAT4X4					m_matProj;

	
};

template<typename T>
HRESULT Engine::CFramework::ChangeScene(T& Functor)
{
	if (m_pCurrentScene != nullptr || m_pRenderer != nullptr)
		Engine::SafeRelease(m_pCurrentScene);

	if (FAILED(Functor(&m_pCurrentScene, &m_pGraphicDevice)))
		return E_FAIL;

	m_pRenderer->BindScene(&m_pCurrentScene);

	return S_OK;
}

END

#endif // Framework_h__
