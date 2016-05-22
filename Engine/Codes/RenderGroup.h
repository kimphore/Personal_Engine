#ifndef RenderGroup_h__
#define RenderGroup_h__

#include "engine_include.h"
#include "Base.h"

/*!
 * \file RenderGroup.h
 * \date 2016/05/22 9:42
 *
 * \author topkpr
 * Contact: user@company.com
 *
 * \brief RenderTarget���� �����ִ� Ŭ����.
			���������� Set, Unset������ ���⼭ �Ͼ��.
			����Ÿ���� �ϳ��� ���ε� �Ǵ��� �̰ɽ�ߵ�.
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)
class CRenderTarget;
class CRenderGroup :public Engine::CBase
{
private:
	enum INFO
	{
		MAX_TARGET = 8
	};
private:
	CRenderGroup();
	~CRenderGroup();

public:
	static CRenderGroup* Create(_int iTargetCnt);
	HRESULT Initialize(_int iTargetCnt);
	void AddTarget(CRenderTarget* pTarget);
	void SetTarget(void);
	void UnsetTarget(void);
	void ClearTarget(void);
	_ulong Release(void);

private:
	typedef vector<CRenderTarget*> TARGETVECTOR;
private:
	TARGETVECTOR m_pTargetVector;
	ID3D11RenderTargetView** m_pTargetArray;
	_int m_iTargetCnt;
	_int m_iCurrCnt;
	ID3D11DeviceContext* m_pDeviceContext;
	ID3D11DepthStencilView* m_pDepthStencilView;
	ID3D11RenderTargetView* m_pBackbufferView;

};

END

#endif // RenderGroup_h__
