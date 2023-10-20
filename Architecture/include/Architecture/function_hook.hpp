#pragma once
#include <functional>
#include <unordered_map>

template<class T, class ... Args>
class function_hook
{
public:
	function_hook(void* adr);
	~function_hook();

	void bind(std::function<void()> listener);

private:
	static T detour(Args... args);
	std::unordered_map<std::function<void()>> listener_list;
};

