#include "function_hook.hpp"

template <typename R, typename... Args>
void function_hook<R(Args...)>::bind(std::function<void()> listener)
{
	listener_list.push_back(listener);
}

template <typename R, typename... Args>
static R function_hook<R(Args...)>::detour(Args... args)
{
	for (const auto& listener : listener_list)
	{
		listener();
	}
	return R();
}

template <typename R, typename... Args>
function_hook<R(Args...)>::function_hook() {}

template <typename R, typename... Args>
function_hook<R(Args...)>& function_hook<R(Args...)>::getInstance(void* target)
{
	auto it = instances.find(target);
	if (it == instances.end())
	{
		function_hook instance();
		instances[target] = instance;
		return instances[target];
	}
	else
	{
		return it->second;
	}
}
template <typename Signature>
std::unordered_map<void*, function_hook<Signature>> function_hook<Signature>::instances;

