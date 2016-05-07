#include "GraphicDevice.h"

IMPLEMENT_SINGLETON(Engine::CGraphicDevice)

USING(Engine)

Engine::CGraphicDevice::CGraphicDevice(void)
{

}

Engine::CGraphicDevice::~CGraphicDevice(void)
{

}

HRESULT Engine::CGraphicDevice::Initialize(_ulong x, _ulong y, _bool fullsize, HWND hWnd)
{
	_ulong createDeviceFlags = 0;

	m_iWinSize[0] = x;
	m_iWinSize[1] = y;
	m_bFullSize = fullsize;
	m_hWnd = hWnd;

#if defined(DEBUG) || defined(_DEBUG)
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_FEATURE_LEVEL featureLevel;
	
	HRESULT hr = D3D11CreateDevice(
		0,							//무슨 어뎁터를 사용할 것인가? 0번은 Default
		D3D_DRIVER_TYPE_HARDWARE,	//3D가속을 사용한다. 나머지는 잘 사용 안할듯
		0,							//소프트웨어 구동기 지정? 무쓸모
		createDeviceFlags,			//Debug일시, 위 플래그 해주면 디버그 메세지 수신가능.
		0, 0,						//피쳐레벨 디폴트?
		D3D11_SDK_VERSION,
		&m_pDevice,
		&featureLevel,				//지원되는 기능을 넣어주는듯.
		&m_pContext
	);

	if (FAILED(hr))
	{
		MSGBOX(L"GraphicDevice Create Failed.");
		return E_FAIL;
	}

	if (featureLevel != D3D_FEATURE_LEVEL_11_0)
	{
		MSGBOX(L"Feature Level 11 Unsupported.");
		return E_FAIL;
	}

	//Device 생성

	_uint iMsaaQuality;

	hr = m_pDevice->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM,
		4, &iMsaaQuality);

	if (FAILED(hr))
	{
		MSGBOX(L"MultiSampling Check Failed.");
		return E_FAIL;
	}

	assert(iMsaaQuality > 0);

	//멀티 샘플링 지원여부 확인
	//A four-component, 32-bit unsigned-normalized-integer 
	//format that supports 8 bits per channel including alpha.

	DXGI_SWAP_CHAIN_DESC chainDesc;
	chainDesc.BufferDesc.Width = m_iWinSize[0];
	chainDesc.BufferDesc.Height = m_iWinSize[1];
	chainDesc.BufferDesc.RefreshRate.Numerator = 60;
	chainDesc.BufferDesc.RefreshRate.Denominator = 1;
	chainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	chainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	chainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	if (m_bEnableMsaa == true)
	{
		chainDesc.SampleDesc.Count = 4;
		chainDesc.SampleDesc.Quality = iMsaaQuality - 1;
	}
	else
	{
		chainDesc.SampleDesc.Count = 1;
		chainDesc.SampleDesc.Quality = 0;
	}

	chainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	chainDesc.BufferCount = 1;
	chainDesc.OutputWindow = m_hWnd;
	chainDesc.Windowed = m_bFullSize;
	chainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	chainDesc.Flags = 0;

	//스왑체인 구조체 정의

	IDXGIDevice* pDxgiDevice = NULL;
	HR(m_pDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&pDxgiDevice));

	IDXGIAdapter* pDxgiAdapter = NULL;
	HR(pDxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)pDxgiAdapter));

	IDXGIFactory* pDxgiFactory = NULL;
	HR(pDxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&pDxgiFactory));

	HR(pDxgiFactory->CreateSwapChain(m_pDevice, &chainDesc, &m_pSwapChain));

	ReleaseCOM(pDxgiDevice);
	ReleaseCOM(pDxgiAdapter);
	ReleaseCOM(pDxgiFactory);
	
	//스왑체인 생성 끝
	ID3D11Texture2D* backBuffer;
	//스왑체인으로부터 받아온 백버퍼 포인터.
	m_pSwapChain->GetBuffer(0, _uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));
	m_pDevice->CreateRenderTargetView(backBuffer, 0, &m_pRenderTargetView);

	ReleaseCOM(backBuffer);//GetBuffer시에 Ref가 1 추가되므로 Release.

	D3D11_TEXTURE2D_DESC depthStencilDesc;
	depthStencilDesc.Width = m_iWinSize[0];
	depthStencilDesc.Height = m_iWinSize[1];
	depthStencilDesc.MipLevels = 1;
	depthStencilDesc.ArraySize = 1;
	depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	if (m_bEnableMsaa == true)
	{
		depthStencilDesc.SampleDesc.Count = 4;
		depthStencilDesc.SampleDesc.Quality = iMsaaQuality - 1;
	}
	else
	{
		depthStencilDesc.SampleDesc.Count = 1;
		depthStencilDesc.SampleDesc.Quality = 0;
	}

	depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
	depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthStencilDesc.CPUAccessFlags = 0;
	depthStencilDesc.MiscFlags = 0;

	HR(m_pDevice->CreateTexture2D(&depthStencilDesc, 0, &m_pDepthStencilBuffer));
	HR(m_pDevice->CreateDepthStencilView(m_pDepthStencilBuffer, 0, &m_pDepthStencilView));

	m_pContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);

	m_tScreenViewport.TopLeftX = 0.f;
	m_tScreenViewport.TopLeftY = 0.f;
	m_tScreenViewport.Width = static_cast<float>(m_iWinSize[0]);
	m_tScreenViewport.Height = static_cast<float>(m_iWinSize[1]);
	m_tScreenViewport.MinDepth = 0.f;
	m_tScreenViewport.MaxDepth = 0.f;

	m_pContext->RSSetViewports(1, &m_tScreenViewport);

	return S_OK;
}