#ifndef Component_h__
#define Component_h__

#include "engine_include.h"
#include "Base.h"

BEGIN(Engine)

class ENGINE_DLL CComponent :public Engine::CBase
{
private:
	explicit CComponent(void);
	~CComponent();

public:
	virtual _ulong	Update(const _float& fTimeDelta);
	virtual void	Render(void);
	_ulong			Release(void);
};

END

#endif // Component_h__
