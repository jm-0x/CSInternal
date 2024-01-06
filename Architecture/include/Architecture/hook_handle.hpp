#pragma once
#include "hook_group.hpp"
#include <functional>





template<auto func, int tag>
struct hook_handle
{
    
    using func_ptr_t = decltype(func);
    using hook_group_t = hook_group<func_ptr_t>;

    hook_handle() : already_hooked(false){}

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
    static bool already_hooked;
};
//silly work-around to make sure each specilization is unique.
//the problem occurs because we cannot differeniate between function with the same signature but unique addresses,
//i.e we cannot actually specialize over a function type, only its traits

//NOTE -  The uniqueness is guaranteed within a single translation unit. If the same template alias is used in different translation units
// , the __COUNTER__ values could overlap, leading to non-unique specializations across the entire program.
template <auto func> 
using hook_handle = hook_handle_t<func, __COUNTER__>;