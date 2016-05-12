#include "Component.h"

USING(Engine)


Engine::CComponent::CComponent(void)
{

}

Engine::CComponent::~CComponent()
{

}

_ulong Engine::CComponent::Update(const _float& fTimeDelta)
{
	return RET_NONE;
}

void Engine::CComponent::Render(void)
{

}

_ulong Engine::CComponent::Release(void)
{
	//한단계 더 내려가야 하므로, 여기선 따로 삭제는 하지 않음.

	return Engine::CBase::Release();
}

