#pragma once
#include <hook_group.hpp>



template<auto func>
struct hook_handle
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
