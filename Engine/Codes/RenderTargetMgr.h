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
	
private:
	CRenderGroup* FindGroup(const TCHAR* pszKey);
private:
	typedef map<const TCHAR*, CRenderGroup*> RGROUPMAP;
private:
	RGROUPMAP m_mapGroup;


};


END

#endif // RenderTargetMgr_h__
