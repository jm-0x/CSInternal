#include <iostream>
#include "Architecture/hook_handle.hpp"
int test()
{
    
}
int main()
{
    hook_handle<test> x;
    x.try_attach_hook();
    
    std::cin.get();
    return 0;
}