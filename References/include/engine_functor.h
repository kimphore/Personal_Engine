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
}
#endif // engine_functor_h__
