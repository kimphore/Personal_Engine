#ifndef Timer_h__
#define Timer_h__

#include "engine_include.h"
#include "Base.h"

/*!
 * \class Timer Class
 *
 * \brief ƽŸ���� ��� Ŭ����. �������� �Ѱ��ָ� ����Ʈ�ɾ���.
 *
 * \author topkpr
 * \date 5�� 2016
 */

BEGIN(Engine)

class ENGINE_DLL CTimer : public Engine::CBase
{
private:
	explicit CTimer(_uint iFrameLimit);
	virtual ~CTimer();

public:
	static CTimer* Create(_uint iFrameLimit);

public:
	const _float GetTimeDelta(void) const{
		return m_fTimeDelta;
	}
	void SetFrameLimit(_int iFrameLimit) {
		if (iFrameLimit == 0)
			m_fFrameTick = 0.f;
		else
			m_fFrameTick = 1.f / static_cast<float>(iFrameLimit);
	}

public:
	HRESULT Initialize(void);
	void	Update(void);
	_bool	UpdateFrame(void);
	void	Stop(void);
	void	Start(void);
	
public:
	virtual _ulong Release(void);
	
private:
	_float	m_fTimeDelta;
	_float	m_fFrameTick;//������ ƽ.
	_float	m_fAccumTime;
	_bool	m_bStopped;
private://������
	__int64 m_iBaseTime;
	__int64 m_iPausedTime;
	__int64 m_iStopTime;
	__int64 m_iPrevTime;
	__int64 m_iCurrTime;
	__int64 m_iCpuTick;
	__int64 m_iAccumTime;
	
	
};

END

#endif // Timer_h__
