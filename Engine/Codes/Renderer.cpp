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
	//Singleton은 아니지만 한 인스턴스에 하나만 존재해야 함.
	CRenderer* pRenderer = new CRenderer();
}

HRESULT Engine::CRenderer::Initialize(ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext)
{
	//여기서 Renderer 다 세팅.
}

_ulong Engine::CRenderer::Release(void)
{

}

void Engine::CRenderer::Render(void)
{
	//Render Group별로 랜더.
	Engine::CGraphicDevice::GetInstance()->BeginScene();

	//Render;
	RenderZsort();

	Engine::CGraphicDevice::GetInstance()->EndScene();
}

void Engine::CRenderer::BindScene(CScene** pScene)
{
	//그냥 Render할 SCene만 교체하는 거니까 별다른 처리는 필요 ㄴㄴ
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
	정렬할때 드는 코스트가 더 클듯.
	*/

	for (; iter != iter_end; ++iter)
		(*iter)->Render();
}

void Engine::CRenderer::RenderAlpha(void)
{

}

