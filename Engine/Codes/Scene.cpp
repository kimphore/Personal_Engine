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
	_ulong dwRetCode = Engine::RET_NONE;

	for (_int i = 0; i < m_dwListCnt; ++i) 
	{
		OBJLIST::iterator iter		= m_pObjLists[i].begin();
		OBJLIST::iterator iter_end	= m_pObjLists[i].begin();

		for (; iter != iter_end;)
		{
			//�̰� ���߿�.
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
