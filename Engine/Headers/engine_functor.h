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
			//Releaseó��.
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
	algorithm Header�� ����, �̹� Func�� �ѱ拚 _Func(*_First)�� �ѱ�⿡
	�̹� ���ͷ����Ͱ� ����Ű�� ��ü��.
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
