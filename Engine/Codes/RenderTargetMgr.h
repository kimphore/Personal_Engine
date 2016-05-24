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
 * \brief 랜더타겟 그룹을 관리해주는 클래스.
		  실제 셋, 언셋은 여기서 일어남.
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
	HRESULT Initialize(ID3D11Device** pDevice);
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
	ID3D11Device* m_pGraphicDevice;

};


END

#endif // RenderTargetMgr_h__
