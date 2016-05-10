#include "GameLoop.h"
//#include "engine_export.h"

CGameLoop::CGameLoop(void)
{

}

CGameLoop::~CGameLoop(void)
{

}

CGameLoop* CGameLoop::Create(void)
{
	CGameLoop* pLoop = new CGameLoop();

	if (FAILED(pLoop->Initialize()))
		::SafeRelease(pLoop);
	
	return pLoop;
}

_ulong CGameLoop::Release(void)
{
	//���߿� �Ŵ����� �̷��͵� ���⼭ �ٳ�����.
	delete this;

	return 0;
}

HRESULT CGameLoop::Initialize(void)
{
	/*
	���ӿ� ���� �ʱ�ȭ �κ�.
	���ҽ� �޴��������, �׷��� ����̽�, �����
	�ʱ⿡ �ʿ��� ��� ������ �� �ʱ�ȭ �� �����Ѵ�.
	*/
	return S_OK;
}

void CGameLoop::Render(void)
{
	//��ü ����. Framework�� Render�� ȣ������.
}

CGameLoop::GAME_STATE CGameLoop::Update(const _float& fTimeDelta)
{
	return GS_RUNNING;//�Ϲ������� running;
}
