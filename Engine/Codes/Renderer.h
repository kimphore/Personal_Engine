#ifndef Renderer_h__
#define Renderer_h__

#include "engine_include.h"
#include "GameObject.h"//실제 오브젝트의 랜더함수를 여기서 호출함.

/*!
 * \file Renderer.h
 * \date 2016/05/12 13:15
 *
 * \author Phore
 * Contact: user@company.com
 *
 * \brief 랜더의 코어가 되는 클래스.
		  오브젝트 랜더가 실제로 이루어 지는 부분.
		  디퍼드 랜더링 베이스..로할꺼니까..
		  랜더그룹도 나누고, 랜더타겟별로도 나누고.
		  후처리는 뭐.. 언젠간하겠지
		  옵션에 민감한가?
 *
 * TODO: long description
 *
 * \note
*/

BEGIN(Engine)

class ENGINE_DLL CRenderer
{
	
};

END

#endif // Renderer_h__
