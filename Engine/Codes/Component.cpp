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
	//�Ѵܰ� �� �������� �ϹǷ�, ���⼱ ���� ������ ���� ����.

	return Engine::CBase::Release();
}

