#include "Scene.h"
#include "Layer.h"

USING(Engine)

Engine::CScene::CScene()
	: m_pGraphicDevice(nullptr)
{

}

Engine::CScene::~CScene(void)
{

}

HRESULT Engine::CScene::Initialize(ID3D11Device* pGraphicDevice)
{
	m_pGraphicDevice = pGraphicDevice;

	return S_OK;
}

_ulong Engine::CScene::Update(const _float& fTimeDelta)
{
	
	auto iter = m_mapLayer.begin();
	auto iter_end = m_mapLayer.end();

	for (; iter != iter_end; ++iter)
	{
		//Update�� ���� ���߿� ���̾ �����Ǵ� ���� ����.
		//GameObject�� Layer���ο��� �����ȴ�.
		iter->second->Update(fTimeDelta);
	}

	return Engine::RET_NONE;
}

void Engine::CScene::Render(void)
{
	//�Ϲ����� Render�� �ƴ� "�ɼ�"
	//���������� ������ �ɸ��Ѱ� FPS?
	//Layer�� ���� Render���� �ʴ´�.
}

_ulong Engine::CScene::Release(void)
{
	_ulong dwRefCnt = Engine::CBase::Release();

	if (dwRefCnt == 0)
	{
		//���⿡�� ���ư��°��� Layer�ۿ�����. Layer����.
		for_each(m_mapLayer.begin(), m_mapLayer.end(), Engine::CMapRelease());
		m_mapLayer.clear();
		delete this;
	}
	else
		--dwRefCnt;

	return dwRefCnt;
}

CLayer* Engine::CScene::GetLayer(const TCHAR* pszKey)
{
	auto iter = find_if(m_mapLayer.begin(), m_mapLayer.end(), CTagFinder(pszKey));

	if (iter == m_mapLayer.end())
		return nullptr;

	return iter->second;
}

HRESULT Engine::CScene::AddLayer(const TCHAR* pszKey)
{
	CLayer* pLayer = GetLayer(pszKey);

	if (pLayer != nullptr)//Layer�� �߰��ϴ� ���̱� ������ �������� �ʾƾ� ��.
		return E_FAIL;

	//������ Layer�� �ɼ��̳� �߰��� �͵��� �ϴ��� ���� ������
	//Scene���ο��� ���������.
	
	pLayer = CLayer::Create();

	if (pLayer == nullptr)
		return E_FAIL;

	m_mapLayer.insert(LAYERMAP::value_type(pszKey, pLayer));

	return S_OK;

	
}

list<CGameObject*>* Engine::CScene::GetObjectList(const TCHAR* pszMapKey, const TCHAR* pszListKey)
{
	CLayer* pLayer = GetLayer(pszMapKey);

	if (pLayer == nullptr)
		return nullptr;

	list<CGameObject*>* pList = pLayer->FindObjList(pszMapKey);

	return pList;
}

HRESULT Engine::CScene::AddObject(const TCHAR* pszMapKey, const TCHAR* pszListKey, CGameObject* pObject)
{
	CLayer* pLayer = GetLayer(pszMapKey);

	if (pLayer == nullptr)
		return E_FAIL;

	pLayer->AddObject(pszListKey, pObject);

	return S_OK;
}
