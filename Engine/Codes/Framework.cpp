#include "Framework.h"
#include "Scene.h"
#include "Renderer.h"

USING(Engine)

IMPLEMENT_SINGLETON(Engine::CFramework)

Engine::CFramework::CFramework(void)
	: m_pGraphicDevice(nullptr)
	, m_pCurrentScene(nullptr)
	, m_pRenderer(nullptr)
{

}

Engine::CFramework::~CFramework(void)
{
	Release();
}

void Engine::CFramework::Initialize(ID3D11Device** pDevice)
{
	
}

void Engine::CFramework::Update(const _float& fTimeDelta)
{
	//SceneUpdate

	if (m_pCurrentScene != nullptr)
		m_pCurrentScene->Update(fTimeDelta);
		
}

void Engine::CFramework::Render(void)
{
	//실제 Render는 Renderer에서.

	if (m_pRenderer != nullptr)
		m_pRenderer->Render();
}

void Engine::CFramework::Release(void)
{
	/*
	별 상관은 없을것 같지만.. 
	Renderer에 Scene이 물려있을 것이므로 Scene부터 삭제하자.

	*/

	Engine::SafeRelease(m_pCurrentScene);
	Engine::SafeRelease(m_pRenderer);
}

const CXMMATRIX& Engine::CFramework::GetMatrix(MATRIX_OPTION eOption)
{
	XMMATRIX matRet;

	switch (eOption)
	{
	case MAT_VIEW:
		matRet = XMLoadFloat4x4(&m_matView);
		break;
	case MAT_PROJ:
		matRet = XMLoadFloat4x4(&m_matProj);
		break;
	case MAT_IDEN:
	default:
		matRet = XMMatrixIdentity();
		break;
	}

	return matRet;
}

const void Engine::CFramework::SetMatrix(MATRIX_OPTION eOption, CXMMATRIX rMat)
{
	switch (eOption)
	{
	case MAT_VIEW:
		break;
	case MAT_PROJ:
		break;
	}
}
