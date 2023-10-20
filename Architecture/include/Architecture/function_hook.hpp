#pragma once
#include <functional>
#include <unordered_map>
#include <vector>

template<typename Signature>
class function_hook;

template<class R, class ...Args>
class function_hook<R(Args...)>
{
public:
	void bind(std::function<void()> listener);

	static R detour(Args... args);

	static function_hook& getInstance(void* target);
private:
	function_hook();

	static std::vector<std::function<void()>> listener_list;
	static std::unordered_map<void*, function_hook> instances;
};
