#ifndef GraphicDevice_h__
#define GraphicDevice_h__

#include "engine_include.h"

/*!
 * \class CGraphicDevice
 *
 * \brief 그래픽 디바이스 클래스.
 *
 * \author topkpr
 * \date 5월 2016
 */

BEGIN(Engine)

class ENGINE_DLL CGraphicDevice 
{
	DECLARE_SINGLETON(CGraphicDevice)
private:
	explicit CGraphicDevice(void);
public:
	~CGraphicDevice(void);

public:
	HRESULT Initialize(_ulong x, _ulong y, _bool fullsize, HWND hWnd);


private:
	HWND						m_hWnd;
private:
	ID3D11Device*				m_pDevice;
	//자원할당, 기능지원 체크.
	ID3D11DeviceContext*		m_pContext;
	//랜더 대상 설정, 자원 그래픽카드에 바인딩, 랜더링 명령 지시
	IDXGISwapChain*				m_pSwapChain;
	ID3D11Texture2D*			m_pDepthStencilBuffer;
	ID3D11RenderTargetView*		m_pRenderTargetView;
	ID3D11DepthStencilView*		m_pDepthStencilView;
	D3D11_VIEWPORT				m_tScreenViewport;

private:
	_ulong						m_iWinSize[2];
	_bool						m_bFullSize;
	_bool						m_bEnableMsaa;

};

END

#endif // GraphicDevice_h__