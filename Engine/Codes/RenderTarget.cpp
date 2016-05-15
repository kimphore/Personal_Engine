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

}

HRESULT Engine::CRenderTarget::Initialize(ID3D11Device** ppGraphicDevice, _ulong x, _ulong y, DXGI_FORMAT format, RenderInfo& tInfo)
{

}

