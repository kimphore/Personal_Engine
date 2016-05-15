#ifndef engine_enum_h__
#define engine_enum_h__

namespace Engine
{
	enum RET_CODE
	{
		RET_NONE = 0,
		RET_DESTROY = 99
	};

	enum MATRIX_OPTION
	{
		MAT_IDEN = 0,
		MAT_VIEW = 1,
		MAT_PROJ = 2
	};

	enum RENDER_GROUP
	{
		RENDER_PRIORITY,
		RENDER_ZSORT,
		RENDER_SHADOW,
		RENDER_ALPHA,
		RENDER_EFFECT,
		RENDER_UI,
		RENDER_END
	};

}

#endif // engine_enum_h__
