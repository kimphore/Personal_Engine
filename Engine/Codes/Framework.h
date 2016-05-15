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
 * \brief 게임전체적인 관리를 해주는 클래스.
			씬과 랜더를 물고있고,
			랜더부분과 모든 오브젝트들이 이 아래서 돌아간다.
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

public://외부와의 통신을 위한 함수들
	/*
		외부 <-----Framework------->Scene,Renderer 내부
	*/
	const CXMMATRIX& GetMatrix(MATRIX_OPTION eOption);
	const void SetMatrix(MATRIX_OPTION eOption, CXMMATRIX rMat);

private:
	ID3D11Device*	m_pGraphicDevice;
	CScene*			m_pCurrentScene;
	CRenderer*		m_pRenderer;

private://Framework로써 저장해야 될 부분. 뷰, 플젝션행렬, 옵션값 등
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
