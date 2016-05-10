#ifndef GameLoop_h__
#define GameLoop_h__

/*!
 * \file GameLoop.h
 * \date 2016/05/10 15:39
 *
 * \author Phore
 * Contact: user@company.com
 *
 * \brief �⺻������ �� ������ ������ ���ư���.
		  Framework���� ���� "����"�󿡼��� ���η����̰�,
		  �̰��� "Ŭ���̾�Ʈ"���� ���η����̴�.
		  ��... ��������� ���ӷ��� �ȿ��� �����ӿ�ũ�� ���ư��� ��.
		  ���� �̱���ȭ �� �ʿ�� ����.
 *
 * TODO: long description
 *
 * \note
*/

#include "include.h"

class CGameLoop
{
public://���� ���� �Ǵ� enum��
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
	//���ϰ����� ������ �������� �ȳ������� �Ǵ���.
	GAME_STATE Update(const _float& fTimeDelta);
};

#endif // GameLoop_h__
