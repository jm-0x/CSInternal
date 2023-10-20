#pragma once
#include <functional>
#include <unordered_map>
#include <vector>

template<typename Signature>
class function_hook
{

private:
	//Evil
	static std::unordered_map<void*, function_hook> instances;

};

template<typename R, typename ...Args>
class function_hook<R(Args...)>
{
public:
	void bind(std::function<void()> listener);
	static R detour(Args... args);
	static function_hook& getInstance(void* target);
private:
	function_hook();
	static std::vector<std::function<void()>> listener_list;
};
