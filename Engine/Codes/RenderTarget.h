#ifndef RenderTarget_h__
#define RenderTarget_h__

#include "engine_include.h"
#include "Base.h"

/*!
 * \file RenderTarget.h
 * \date 2016/05/15 10:52
 *
 * \author Phore
 * Contact: user@company.com
 *
 * \brief RenderTarget세팅을 위한 클래스.
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)

class CRenderTarget : public Engine::CBase
{
private:
	explicit CRenderTarget(void);
	~CRenderTarget();

public:
	static CRenderTarget* Create(ID3D11Device** ppGraphicDevice, _ulong x, _ulong y, DXGI_FORMAT format, RenderInfo& tInfo);

public:
	HRESULT Initialize(ID3D11Device** ppGraphicDevice, _ulong x, _ulong y, DXGI_FORMAT format, RenderInfo& tInfo);

	_ulong Release(void);
public://Get Function
	ID3D11RenderTargetView** GetTargetView(void) {
		return &m_pTargetView;
	}
private:
	_ulong						m_iTargetSizeX;
	_ulong						m_iTargetSizeY;
	RenderInfo					m_tRenderInfo;
private:
	ID3D11Device*				m_pGraphicDevice;
	ID3D11Texture2D*			m_pTargetTexture;
	ID3D11RenderTargetView*		m_pTargetView;
	ID3D11ShaderResourceView*	m_pShaderResourceView;
};

END
#endif // RenderTarget_h__