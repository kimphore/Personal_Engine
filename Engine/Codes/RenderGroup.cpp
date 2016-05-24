#include "RenderGroup.h"
#include "RenderTarget.h"
#include "GraphicDevice.h"

USING(Engine)

Engine::CRenderGroup::CRenderGroup()
	: m_pDeviceContext(nullptr)
	, m_pDepthStencilView(nullptr)
	, m_pBackbufferView(nullptr)
	, m_pArrTarget(nullptr)
	, m_pGraphicDevice(nullptr)
	, m_iTargetCnt(0)
{

}

Engine::CRenderGroup::~CRenderGroup()
{

}

CRenderGroup* Engine::CRenderGroup::Create(ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext,
	ID3D11DepthStencilView** ppDepthView, ID3D11RenderTargetView** ppBackbuffer)
{
	CRenderGroup* pGroup = new CRenderGroup();

	if (FAILED(pGroup->Initialize(ppDevice, ppContext, ppDepthView, ppBackbuffer)))
	{
		SafeDelete(pGroup);
	}

	return pGroup;
}

HRESULT Engine::CRenderGroup::Initialize(ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext,
	ID3D11DepthStencilView** ppDepthView, ID3D11RenderTargetView** ppBackbuffer)
{
	m_pArrTarget = new ID3D11RenderTargetView*[m_iTargetCnt];

	m_pGraphicDevice = *ppDevice;
	m_pDeviceContext = *ppContext;
	m_pDepthStencilView = *ppDepthView;
	m_pBackbufferView = *ppBackbuffer;

	return S_OK;
}

void Engine::CRenderGroup::AddTarget(ID3D11Device** ppGraphicDevice, _ulong x, _ulong y, DXGI_FORMAT format, RenderInfo& tInfo)
{
	if (m_iTargetCnt >= MAX_TARGET)
		return;

	//CRendertarget을 여길 거쳐서 만들어지도록.
	CRenderTarget* pTarget = Engine::CRenderTarget::Create(&m_pGraphicDevice, x, y, format, tInfo);

	if (pTarget == NULL)
		return;

	m_pvecTarget.emplace_back(pTarget);

	ID3D11RenderTargetView** pArr = new ID3D11RenderTargetView*[m_pvecTarget.size()];
	
	memcpy(m_pArrTarget, pArr, sizeof(ID3D11RenderTargetView*) * (m_pvecTarget.size() - 1));
	Engine::Swap(pArr, m_pArrTarget);//포인터 스왑 후
	
	delete[] pArr;//과거의 리스트 폐기.

	m_pArrTarget[m_pvecTarget.size() - 1] = *(pTarget->GetTargetView());

	++m_iTargetCnt;

}

void Engine::CRenderGroup::SetTarget(void)
{
	m_pDeviceContext->OMSetRenderTargets(m_iTargetCnt, m_pArrTarget, m_pDepthStencilView);
}

void Engine::CRenderGroup::UnsetTarget(void)
{
	//백버퍼로 돌려줌.
	m_pDeviceContext->OMSetRenderTargets(1, &m_pBackbufferView, m_pDepthStencilView);
}

void Engine::CRenderGroup::ClearTarget(void)
{
	//Depth는 냅..두자?
	for (_int i = 0; i < m_iTargetCnt; ++i)
		m_pDeviceContext->ClearRenderTargetView(m_pArrTarget[i], Color::blue);
}

_ulong Engine::CRenderGroup::Release(void)
{
	_ulong dwRefCnt = CBase::Release();

	if (dwRefCnt == 0)
	{
		delete[] m_pArrTarget;

		auto iter = m_pvecTarget.begin();
		auto iter_end = m_pvecTarget.end();

		for (; iter != iter_end; ++iter)
			(*iter)->Release();

		m_pvecTarget.clear();

		delete this;
	}
	else
		--dwRefCnt;

	return dwRefCnt;

}

