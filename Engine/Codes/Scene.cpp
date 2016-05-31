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
		//Update가 도는 도중에 레이어가 삭제되는 일은 없다.
		//GameObject는 Layer내부에서 삭제된다.
		iter->second->Update(fTimeDelta);
	}

	return Engine::RET_NONE;
}

void Engine::CScene::Render(void)
{
	//일반적인 Render가 아닌 "옵션"
	//공통적으로 랜더링 될만한게 FPS?
	//Layer는 따로 Render하지 않는다.
}

_ulong Engine::CScene::Release(void)
{
	_ulong dwRefCnt = Engine::CBase::Release();

	if (dwRefCnt == 0)
	{
		//여기에서 돌아가는것은 Layer밖에없다. Layer삭제.
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

	if (pLayer != nullptr)//Layer를 추가하는 것이기 때문에 존재하지 않아야 함.
		return E_FAIL;

	//어차피 Layer는 옵션이나 추가할 것들이 일단은 없기 떄문에
	//Scene내부에서 만들어주자.
	
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
