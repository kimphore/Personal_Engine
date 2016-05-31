#include "RenderTargetMgr.h"
#include "RenderGroup.h"
#include "GraphicDevice.h"

USING(Engine)

IMPLEMENT_SINGLETON(CRenderTargetManager)

Engine::CRenderTargetManager::CRenderTargetManager()
	: m_pGraphicDevice(nullptr)
	, m_pDeviceContext(nullptr)
	, m_pDepthStencilView(nullptr)
	, m_pBackbufferView(nullptr)
{

}

Engine::CRenderTargetManager::~CRenderTargetManager()
{

}

HRESULT Engine::CRenderTargetManager::Initialize(ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext, ID3D11DepthStencilView** ppDepthView, ID3D11RenderTargetView** ppBackbuffer)
{
	m_pGraphicDevice = *ppDevice;
	m_pDeviceContext = *ppContext;
	m_pDepthStencilView = *ppDepthView;
	m_pBackbufferView = *ppBackbuffer;

	return S_OK;
}



HRESULT Engine::CRenderTargetManager::AddRenderTarget(const TCHAR* pszGroupKey, _ulong x, _ulong y, DXGI_FORMAT format, RenderInfo& tInfo)
{
	CRenderGroup* pGroup = FindGroup(pszGroupKey);

	if (pGroup == NULL)
	{
		//만약 그룹이 존재하지 않는다면, 삽입하고 진행.
		pGroup = CRenderGroup::Create(&m_pGraphicDevice, &m_pDeviceContext, &m_pDepthStencilView, &m_pBackbufferView);

		if (pGroup == NULL)
		{
			MSGBOX(L"RenderGroup Add Failed");
			assert(0);
			return E_FAIL;
		}
		
		m_mapGroup.insert(RGROUPMAP::value_type(pszGroupKey, pGroup));
	}

	pGroup->AddTarget(Engine::CGraphicDevice::GetInstance()->GetDevice(), x
		, y, format, tInfo);

	return S_OK;
}

void Engine::CRenderTargetManager::SetRenderGroup(const TCHAR* pszGroupKey)
{
	CRenderGroup* pGroup = FindGroup(pszGroupKey);

	if (pGroup == NULL)
		return;

	pGroup->SetTarget();
}

void Engine::CRenderTargetManager::UnsetRenderGroup(const TCHAR* pszGroupKey)
{
	CRenderGroup* pGroup = FindGroup(pszGroupKey);

	if (pGroup == NULL)
		return;

	pGroup->UnsetTarget();
}

void Engine::CRenderTargetManager::ClearRenderGroup(const TCHAR* pszGorupKey)
{
	CRenderGroup* pGroup = FindGroup(pszGorupKey);

	if (pGroup == NULL)
		return;

	pGroup->ClearTarget();
}

CRenderGroup* Engine::CRenderTargetManager::FindGroup(const TCHAR* pszKey)
{
	auto iter = find_if(m_mapGroup.begin(), m_mapGroup.end(), Engine::CTagFinder(pszKey));

	if (iter == m_mapGroup.end())
		return NULL;

	return iter->second;
}

void Engine::CRenderTargetManager::Release(void)
{
	for_each(m_mapGroup.begin(), m_mapGroup.end(), Engine::CMapRelease());
	m_mapGroup.clear();
}

