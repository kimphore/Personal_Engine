#ifndef engine_struct_h__
#define engine_struct_h__

namespace Engine
{
	typedef struct tagRenderInfo
	{
		//랜더타겟 화면 출력용 구조체.
		unsigned int iSizeX;
		unsigned int iSizeY;
		unsigned int iPosX;
		unsigned int iPosY;
	}RenderInfo;

	//Vertex 타입별 구조체
	namespace Vertex
	{

	}
}

#endif // engine_struct_h__
