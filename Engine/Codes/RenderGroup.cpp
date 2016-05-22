#include "RenderGroup.h"
#include "RenderTarget.h"
#include "GraphicDevice.h"

USING(Engine)

Engine::CRenderGroup::CRenderGroup()
	: m_pDeviceContext(nullptr)
	, m_pDepthStencilView(nullptr)
	, m_pBackbufferView(nullptr)
{

}

Engine::CRenderGroup::~CRenderGroup()
{

}

CRenderGroup* Engine::CRenderGroup::Create(_int iTargetCnt)
{
	CRenderGroup* pGroup = new CRenderGroup();

	if (FAILED(pGroup->Initialize(iTargetCnt)))
	{
		SafeDelete(pGroup);
	}

	return pGroup;
}

HRESULT Engine::CRenderGroup::Initialize(_int iTargetCnt)
{
	if (iTargetCnt > MAX_TARGET)
		return E_FAIL;

	return S_OK;
}

void Engine::CRenderGroup::AddTarget(CRenderTarget* pTarget)
{
	//복사생성자를 이용하는 것이 아닌 본체 그대로.
	//하지만 포인터 저장하니까 별생관없을꺼같은데;;
	m_pTargetVector.emplace_back(pTarget);
}

void Engine::CRenderGroup::SetTarget(void)
{
	
}

void Engine::CRenderGroup::UnsetTarget(void)
{

}

void Engine::CRenderGroup::ClearTarget(void)
{

}

_ulong Engine::CRenderGroup::Release(void)
{

}

