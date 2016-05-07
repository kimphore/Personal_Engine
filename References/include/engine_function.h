#ifndef engine_function_h__
#define engine_function_h__

namespace Engine
{
	template <typename T>
	void SafeDelete(T& Instance)
	{
		if (Instance != NULL)
		{
			delete Instance;
			Instance = NULL;
		}
	}

	template <typename T>
	_ulong SafeRelease(T& Instance)
	{
		_ulong dwRefCnt = 0;

		if (Instance != NULL)
		{
			dwRefCnt = Instance->Release();

			if (dwRefCnt == 0)
				Instance = NULL;
		}

		return dwRefCnt;
	}

}

#endif // engine_function_h__
