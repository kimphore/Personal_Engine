#include "Renderer.h"
#include "Scene.h"
#include "GraphicDevice.h"

USING(Engine)


Engine::CRenderer::CRenderer()
{

}

Engine::CRenderer::~CRenderer(void)
{

}

CRenderer* Engine::CRenderer::Create()
{
	//Singleton�� �ƴ����� �� �ν��Ͻ��� �ϳ��� �����ؾ� ��.
	CRenderer* pRenderer = new CRenderer();
}

HRESULT Engine::CRenderer::Initialize(ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext)
{
	//���⼭ Renderer �� ����.
}

_ulong Engine::CRenderer::Release(void)
{

}

void Engine::CRenderer::Render(void)
{
	//Render Group���� ����.
	Engine::CGraphicDevice::GetInstance()->BeginScene();

	//Render;
	RenderZsort();

	Engine::CGraphicDevice::GetInstance()->EndScene();
}

void Engine::CRenderer::BindScene(CScene** pScene)
{
	//�׳� Render�� SCene�� ��ü�ϴ� �Ŵϱ� ���ٸ� ó���� �ʿ� ����
	m_pCurrentScene = *pScene;
}

void Engine::CRenderer::ClearObjectGroup(void)
{
	for (_int i = 0; i < RENDER_END; ++i)
	{
		m_arrRenderGroup[i].clear();
	}
}

void Engine::CRenderer::RenderZsort(void)
{
	auto iter = m_arrRenderGroup[RENDER_ZSORT].begin();
	auto iter_end = m_arrRenderGroup[RENDER_ZSORT].end();

	/*
	�����Ҷ� ��� �ڽ�Ʈ�� �� Ŭ��.
	*/

	for (; iter != iter_end; ++iter)
		(*iter)->Render();
}

void Engine::CRenderer::RenderAlpha(void)
{

}

