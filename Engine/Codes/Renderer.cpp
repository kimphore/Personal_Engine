#include "Renderer.h"
#include "Scene.h"
#include "GraphicDevice.h"

USING(Engine)


Engine::CRenderer::CRenderer(void)
{

}

Engine::CRenderer::~CRenderer(void)
{

}

CRenderer* Engine::CRenderer::Create()
{
	
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

	for (; iter != iter_end; ++iter)
		(*iter)->Render();
}

void Engine::CRenderer::RenderAlpha(void)
{

}

