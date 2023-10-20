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

template<auto func>
struct hooked_function_handle
{
    using func_ptr_t = decltype(func);
    using hook_group_t = hook_group<func_ptr_t>;

    static void try_attach_hook()
    {
        if (already_hooked) return;
        func_ptr_t hook_function = hook_group_t::hook_function<func>;
        already_hooked = true;
    }

    //this could also instead be using perfect forwarding, but a consideration for another day
    static void attach_listener(std::function<void()> listener)
    {
        hook_group_t::listeners[func].emplace_back(std::move(listener));
    }

private:
    static bool already_hooked = false;
};

