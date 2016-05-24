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
	static CRenderGroup* Create(void);
	HRESULT Initialize(void);
	void AddTarget(ID3D11Device** ppGraphicDevice, _ulong x, _ulong y, DXGI_FORMAT format, RenderInfo& tInfo);
	void SetTarget(void);
	void UnsetTarget(void);
	void ClearTarget(void);
	_ulong Release(void);

private:
	typedef vector<CRenderTarget*> TARGETVECTOR;
private:
	TARGETVECTOR m_pvecTarget;
	ID3D11RenderTargetView** m_pArrTarget;
	_int m_iTargetCnt;
	ID3D11Device* m_pGraphicDevice;
	ID3D11DeviceContext* m_pDeviceContext;
	ID3D11DepthStencilView* m_pDepthStencilView;
	ID3D11RenderTargetView* m_pBackbufferView;

};

END

#endif // RenderGroup_h__
