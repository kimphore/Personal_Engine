#include "Framework.h"

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

	//if(m_pCurrentScene != nullptr)
		
}

void Engine::CFramework::Render(void)
{
	//���� Render�� Renderer����.

	//if(m_pRenderer != nullptr)
}

void Engine::CFramework::Release(void)
{
	/*
	�� ����� ������ ������.. 
	Renderer�� Scene�� �������� ���̹Ƿ� Scene���� ��������.

	*/

	Engine::SafeRelease(m_pCurrentScene);
	Engine::SafeRelease(m_pRenderer);
}
