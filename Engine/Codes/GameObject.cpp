#include "GameObject.h"
#include "Component.h"

USING(Engine)

Engine::CGameObject::CGameObject()
	: m_pGraphicDevice(nullptr)
	, m_iObjectID(0)
{

}

Engine::CGameObject::~CGameObject()
{

}

_ulong Engine::CGameObject::Update(const _float& fTimeDelta)
{
	COMPOMAP::iterator iter		= m_mapComponent.begin();
	COMPOMAP::iterator iter_end = m_mapComponent.end();

	_ulong dwRetCode = RET_NONE;

	for (; iter != iter_end; ++iter)
	{
		//컴포넌트는 중간에 삭제되지 않음.? 일단..
		dwRetCode = iter->second->Update(fTimeDelta);

		if (dwRetCode == RET_DESTROY)
			return RET_DESTROY;
	}

	return Engine::RET_NONE;
}

HRESULT Engine::CGameObject::SetComponent(void)
{

}

_ulong Engine::CGameObject::Release(void)
{

	_ulong dwRefCnt = Engine::CBase::Release();

	if (dwRefCnt == 0)
	{
		for_each(m_mapComponent.begin(), m_mapComponent.end(), Engine::CMapRelease());
	}

	return dwRefCnt;

}

const CComponent* Engine::CGameObject::GetComponent(const TCHAR* pszKey)
{
	CComponent* pCompo = nullptr;
	
	COMPOMAP::iterator iter = find_if(m_mapComponent.begin(), m_mapComponent.end(), CTagFinder(pszKey));

	if (iter != m_mapComponent.end())
		pCompo = iter->second;

	return pCompo;
}

