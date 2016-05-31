#include "Layer.h"
#include "GameObject.h"

USING(Engine)

Engine::CLayer::CLayer(void)
{

}

Engine::CLayer::~CLayer()
{

}

list<CGameObject*>* Engine::CLayer::FindObjList(const TCHAR* pszKey)
{
	auto iter = find_if(m_mapObject.begin(), m_mapObject.end(), Engine::CTagFinder(pszKey));

	if (iter == m_mapObject.end())
		return nullptr;

	return &iter->second;
}

CLayer* Engine::CLayer::Create(void)
{
	CLayer* pLayer = new CLayer();
	//딱히 Initialize할건 없을듯.
	return pLayer;
}

_int Engine::CLayer::Update(const float& fTimeDelta)
{
	auto iter_map = m_mapObject.begin();
	auto iter_map_end = m_mapObject.end();

	for (; iter_map != iter_map_end; ++iter_map)
	{
		auto iter_list = iter_map->second.begin();
		auto iter_list_end = iter_map->second.end();

		for (; iter_list != iter_list_end;)
		{
			_ulong dwRetCode = (*iter_list)->Update(fTimeDelta);

			if (dwRetCode == Engine::RET_DESTROY)
			{
				//Erase;
				Engine::SafeRelease(*iter_list);
				iter_map->second.erase(iter_list);
			}
			else
				++iter_list;
		}
	}

	return Engine::RET_NONE;
}

void Engine::CLayer::AddObject(const TCHAR* pszKey, CGameObject* pObject)
{
	auto pList = FindObjList(pszKey);

	if (pList == nullptr)
	{
		m_mapObject.insert(OBJMAP::value_type(pszKey, list<CGameObject*>()));
		pList = FindObjList(pszKey);
	}

	pList->push_back(pObject);
}

void Engine::CLayer::ReleaseList(const TCHAR* pszKey)
{
	auto pList = FindObjList(pszKey);

	if (pList == nullptr)
		return;

	auto iter = pList->begin();
	auto iter_end = pList->end();

	for (; iter != iter_end; ++iter)
	{
		Engine::SafeRelease(*iter);
	}
	pList->clear();

	auto iter_map = find_if(m_mapObject.begin(), m_mapObject.end(), CTagFinder(pszKey));

	if (iter_map != m_mapObject.end())
		m_mapObject.erase(iter_map);
}

_ulong Engine::CLayer::Release(void)
{
	_ulong dwRefCnt = CBase::Release();

	if (dwRefCnt == 0)
	{
		auto iter_map = m_mapObject.begin();
		auto iter_map_end = m_mapObject.end();

		for (; iter_map != iter_map_end; ++iter_map)
		{
			for_each(iter_map->second.begin(), iter_map->second.end(), CSingleRelease());
			iter_map->second.clear();
		}

		m_mapObject.clear();

		delete this;
	}
	else
	{
		--dwRefCnt;
	}

	return dwRefCnt;
}

