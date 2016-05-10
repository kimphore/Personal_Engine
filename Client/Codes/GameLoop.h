#ifndef GameLoop_h__
#define GameLoop_h__

/*!
 * \file GameLoop.h
 * \date 2016/05/10 15:39
 *
 * \author Phore
 * Contact: user@company.com
 *
 * \brief 기본적으로 이 위에서 게임이 돌아간다.
		  Framework같은 경우는 "엔진"상에서의 메인루프이고,
		  이것은 "클라이언트"상의 메인루프이다.
		  뭐... 결론적으로 게임루프 안에서 프레임워크가 돌아가는 것.
		  딱히 싱글톤화 할 필요는 없다.
 *
 * TODO: long description
 *
 * \note
*/

#include "include.h"

class CGameLoop
{
public://게임 상태 판단 enum값
	enum GAME_STATE{GS_RUNNING = 0, GS_QUIT = 1};
private:
	explicit CGameLoop(void);
	~CGameLoop(void);
public:
	static CGameLoop* Create(void);
	_ulong Release(void);
private:
	HRESULT Initialize(void);
public:
	void Render(void);
	//리턴값으로 게임이 끝났는지 안끝났는지 판단함.
	GAME_STATE Update(const _float& fTimeDelta);
};

#endif // GameLoop_h__
