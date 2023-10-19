#include "IHook.hpp"

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