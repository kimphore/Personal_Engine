#ifndef GraphicDevice_h__
#define GraphicDevice_h__

#include "engine_include.h"

/*!
 * \class CGraphicDevice
 *
 * \brief �׷��� ����̽� Ŭ����.
 *
 * \author topkpr
 * \date 5�� 2016
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
	//�ڿ��Ҵ�, ������� üũ.
	ID3D11DeviceContext*		m_pContext;
	//���� ��� ����, �ڿ� �׷���ī�忡 ���ε�, ������ ��� ����
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