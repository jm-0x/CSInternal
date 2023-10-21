#include <unordered_map>
#include <vector>
#include <functional>


template<typename T>
struct hook_group;

template<typename R, typename ... Args>
struct hook_group<R(Args...)>
{
    using func_ptr_t = R(*)(Args...);

    template<func_ptr_t func>
    static R hook_function(Args...)
    {
        auto our_listeners = listeners.find(func);
        if (our_listeners != listeners.end())
        {
            for (const auto& listener : our_liseners.second)
            {
                listener();
            }
        }
    }

    static std::unordered_map<func_ptr_t, std::vector<std::function<void()>>> listeners;
};