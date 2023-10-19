#pragma once
#include <functional>

class IHook
{
public:
	IHook();
	virtual ~IHook();
private:
	void bind(std::function<void()> listener);

};