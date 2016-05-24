#ifndef RenderTargetMgr_h__
#define RenderTargetMgr_h__

#include "engine_include.h"

/*!
 * \file RenderTargetMgr.h
 * \date 2016/05/22 22:50
 *
 * \author topkpr
 * Contact: user@company.com
 *
 * \brief ����Ÿ�� �׷��� �������ִ� Ŭ����.
		  ���� ��, ����� ���⼭ �Ͼ.
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)
class CRenderGroup;
class CRenderTargetManager
{
	DECLARE_SINGLETON(CRenderTargetManager)
private:
	explicit CRenderTargetManager();
public:
	~CRenderTargetManager();

public:
	HRESULT Initialize(ID3D11Device** ppDevice, ID3D11DeviceContext** ppContext, ID3D11DepthStencilView** ppDepthView, ID3D11RenderTargetView** ppBackbuffer);
	HRESULT AddRenderTarget(const TCHAR* pszGroupKey, _ulong x, _ulong y, DXGI_FORMAT format, RenderInfo& tInfo);
	void SetRenderGroup(const TCHAR* pszGroupKey);
	void UnsetRenderGroup(const TCHAR* pszGroupKey);
	void ClearRenderGroup(const TCHAR* pszGorupKey);
	void Release(void);
private:
	CRenderGroup* FindGroup(const TCHAR* pszKey);
private:
	typedef map<const TCHAR*, CRenderGroup*> RGROUPMAP;
private:
	RGROUPMAP m_mapGroup;
private://�ʿ��� ���� ��ҵ�
	ID3D11Device* m_pGraphicDevice;
	ID3D11DeviceContext* m_pDeviceContext;
	ID3D11DepthStencilView* m_pDepthStencilView;
	ID3D11RenderTargetView* m_pBackbufferView;
};


END

#endif // RenderTargetMgr_h__
