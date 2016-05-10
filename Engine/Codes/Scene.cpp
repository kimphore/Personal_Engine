#include "Scene.h"

USING(Engine)

Engine::CScene::CScene()
	: m_pGraphicDevice(nullptr)
	, m_pObjLists(NULL)
	, m_dwListCnt(0)
{

}

Engine::CScene::~CScene(void)
{

}

HRESULT Engine::CScene::Initialize(ID3D11Device* pGraphicDevice, _ulong dwListCnt)
{
	if (dwListCnt <= 0)
	{ 
		MSGBOX(L"List Num > 0");
		return E_FAIL;
	}
	else
	{
		m_pObjLists = new OBJLIST[dwListCnt];
	}

	m_pGraphicDevice = pGraphicDevice;
}

_ulong Engine::CScene::Update(const _float fTimeDelta)
{
	return 0;
}

void Engine::CScene::Render(void)
{
	//일반적인 Render가 아닌 "옵션"
	//공통적으로 랜더링 될만한게 FPS?
}

_ulong Engine::CScene::Release(void)
{
	_ulong dwRefCnt = Engine::CBase::Release();

	if (dwRefCnt == 0)
	{
		//여기서 나중에 삭제연산 추가해서 삭제연산.

		::SafeDelete(m_pObjLists);
		delete this;
	}
	else
		--dwRefCnt;

	return dwRefCnt;
}
