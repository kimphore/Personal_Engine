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
	//나중에 매니저나 이런것들 여기서 다날려줌.
	delete this;

	return 0;
}

HRESULT CGameLoop::Initialize(void)
{
	/*
	게임에 관한 초기화 부분.
	리소스 메니저라던가, 그래픽 디바이스, 사운드등
	초기에 필요한 모든 정보를 다 초기화 및 세팅한다.
	*/
	return S_OK;
}

void CGameLoop::Render(void)
{
	//전체 랜더. Framework의 Render를 호출해줌.
}

CGameLoop::GAME_STATE CGameLoop::Update(const _float& fTimeDelta)
{
	return GS_RUNNING;//일반적으로 running;
}
