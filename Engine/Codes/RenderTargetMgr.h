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
	
private:
	CRenderGroup* FindGroup(const TCHAR* pszKey);
private:
	typedef map<const TCHAR*, CRenderGroup*> RGROUPMAP;
private:
	RGROUPMAP m_mapGroup;


};


END

#endif // RenderTargetMgr_h__
