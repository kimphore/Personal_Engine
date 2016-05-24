#include "Scene.h"
#include "GameObject.h"

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

		for (_ulong i = 0; i < dwListCnt; ++i)
			m_pObjLists[i] = OBJLIST();
	}

	m_pGraphicDevice = pGraphicDevice;
}

_ulong Engine::CScene::Update(const _float& fTimeDelta)
{
	_ulong dwRetCode = Engine::RET_NONE;

	for (_ulong i = 0; i < m_dwListCnt; ++i) 
	{
		auto iter		= m_pObjLists[i].begin();
		auto iter_end	= m_pObjLists[i].end();

		for (; iter != iter_end;)
		{
			(*iter)->Update(fTimeDelta);
		}
	}

	return 0;
}

void Engine::CScene::Render(void)
{
	//�Ϲ����� Render�� �ƴ� "�ɼ�"
	//���������� ������ �ɸ��Ѱ� FPS?
}

_ulong Engine::CScene::Release(void)
{
	_ulong dwRefCnt = Engine::CBase::Release();

	if (dwRefCnt == 0)
	{
		//���⼭ ���߿� �������� �߰��ؼ� ��������.

		::SafeDelete(m_pObjLists);
		delete this;
	}
	else
		--dwRefCnt;

	return dwRefCnt;
}
