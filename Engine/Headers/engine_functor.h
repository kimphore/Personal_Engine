#ifndef engine_functor_h__
#define engine_functor_h__

namespace Engine
{
	class CTagFinder
	{
	public:
		explicit CTagFinder(const TCHAR* pTag) : m_pTag(pTag) {}
		~CTagFinder() {};

	public:
		template <typename T> bool operator() (T& Pair)
		{
			int iResult = lstrcmp(m_pTag, Pair.first);

			if (iResult == 0)
				return true;
			return false;
		}
	private:
		const TCHAR* m_pTag;
	};

	class CMapRelease
	{
	public:
		explicit CMapRelease() {};
		~CMapRelease();

	public:
		template <typename T> void operator() (T& Pair)
		{
			//Release처리.
			if (Pair.second != nullptr)
			{
				Pair.second->Release();
				Pair.second = nullptr;
			}
		}
	};

	class CSingleRelease
	{
	/*
	algorithm Header에 보면, 이미 Func에 넘길떄 _Func(*_First)로 넘기기에
	이미 이터레이터가 가르키는 객체임.
	*/
	public:
		explicit CSingleRelease(void) {};
		~CSingleRelease() {};

	public:
		template<typename T>
		void operator () (T& iter)
		{
			if (iter != nullptr)
			{
				iter->Release();
				iter = nullptr;
			}
		}
	};
}
#endif // engine_functor_h__
