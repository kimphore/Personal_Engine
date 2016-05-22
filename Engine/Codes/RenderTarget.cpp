#include "RenderTarget.h"

USING(Engine)

Engine::CRenderTarget::CRenderTarget(void)
	: m_pGraphicDevice(nullptr)
	, m_pTargetTexture(nullptr)
	, m_pTargetView(nullptr)
	, m_pShaderResourceView(nullptr)
	, m_iTargetSizeX(0)
	, m_iTargetSizeY(0)
{
	ZeroMemory(&m_tRenderInfo, sizeof(RenderInfo));
}

Engine::CRenderTarget::~CRenderTarget()
{

}

CRenderTarget* Engine::CRenderTarget::Create(ID3D11Device** ppGraphicDevice, _ulong x, _ulong y, DXGI_FORMAT format, RenderInfo& tInfo)
{

	CRenderTarget* pTarget = new CRenderTarget();

	if (FAILED(pTarget->Initialize(ppGraphicDevice, x, y, format, tInfo)))
		SafeDelete(pTarget);

	return pTarget;
}

HRESULT Engine::CRenderTarget::Initialize(ID3D11Device** ppGraphicDevice,n_ulong x, _ulong y, DXGI_FORMAT format, RenderInfo& tInfo)
{
	m_pGraphicDevice = *ppGraphicDevice;
	m_iTargetSizeX = x;
	m_iTargetSizeY = y;
	memcpy(&m_tRenderInfo, &tInfo, sizeof(RenderInfo));

	D3D11_TEXTURE2D_DESC texDesc;
	D3D11_RENDER_TARGET_VIEW_DESC rtDesc;
	D3D11_SHADER_RESOURCE_VIEW_DESC srDesc;

	ZeroMemory(&texDesc, sizeof(D3D11_TEXTURE2D_DESC));

	texDesc.Width = x;
	texDesc.Height = y;
	texDesc.MipLevels = 1;
	texDesc.ArraySize = 1;
	texDesc.Format = format;
	texDesc.SampleDesc.Count = 1;
	texDesc.Usage = D3D11_USAGE_DEFAULT;
	texDesc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	texDesc.CPUAccessFlags = 0;
	texDesc.MiscFlags = 0;

	HRESULT hr = m_pGraphicDevice->CreateTexture2D(&texDesc, NULL, &m_pTargetTexture);

	if (FAILED(hr))
	{
		MSGBOX(L"Render Target Texture Create Failed.");
		assert(0);

		return E_FAIL;
	}

	rtDesc.Format = format;
	rtDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	rtDesc.Texture2D.MipSlice = 0;

	hr = m_pGraphicDevice->CreateRenderTargetView(m_pTargetTexture, &rtDesc, &m_pTargetView);	

	if (FAILED(hr))
	{
		MSGBOX(L"Render Target View Create Failed.");
		assert(0);

		return E_FAIL;
	}

	srDesc.Format = format;
	srDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
	srDesc.Texture2D.MostDetailedMip = 0;
	srDesc.Texture2D.MipLevels = 1;

	hr = m_pGraphicDevice->CreateShaderResourceView(m_pTargetTexture, &srDesc, &m_pShaderResourceView);

	if (FAILED(hr))
	{
		MSGBOX(L"Shader Resource View Create Failed.");
		assert(0);

		return E_FAIL;
	}
	
	return S_OK;
}

_ulong Engine::CRenderTarget::Release(void)
{
	_ulong dwRefCnt = CBase::Release();

	if (dwRefCnt == 0)
	{
		if (m_pShaderResourceView != nullptr)
		{
			m_pShaderResourceView->Release();
			m_pShaderResourceView = nullptr;
		}

		if (m_pTargetView != nullptr)
		{
			m_pTargetView->Release();
			m_pTargetView = nullptr;
		}

		if (m_pTargetTexture != nullptr)
		{
			m_pTargetTexture->Release();
			m_pTargetTexture = nullptr;
		}

		SafeDelete(this);
	}
	else
		--dwRefCnt;

	return dwRefCnt;
}

