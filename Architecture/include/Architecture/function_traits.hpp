template <typename F> 
struct function_traits;

template <typename R, typename... Args>
struct function_traits<R(*)(Args...)>
{
	using pointer = R(*)(Args...);
	using return_type = R;
	using arg_types = std::tuple<Args...>;
	static constexpr std::size_t arg_count = sizeof...(Args...);
	template <std::size_t N> 
	using nth_arg = std::tuple_element_t<N, arg_types>;
	using first_arg = nth_arg<0>;
	using last_arg = nth_arg<arg_count - 1>;
};
