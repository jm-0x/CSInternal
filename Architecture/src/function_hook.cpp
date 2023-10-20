#include "function_hook.hpp"

class IHook
{
public:
	IHook()
	{
	}
	virtual ~IHook() {}
private:
	void bind(std::function<void()> listener)
	{

	}

};