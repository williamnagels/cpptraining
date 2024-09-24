#include <coroutine>
#include <iostream>
#include<vector>
template <typename T>
concept Iterable = requires(T t) {
    // This requires that T has an iterator type and supports begin and end
    typename T::iterator;
    { t.begin() } -> std::same_as<typename T::iterator>;
    { t.end() } -> std::same_as<typename T::iterator>;
};

struct HelloWorldCoro 
{
    struct promise_type { // compiler looks for `promise_type`
        HelloWorldCoro get_return_object() { return this; }    
        std::suspend_always initial_suspend() { return {}; }        
        std::suspend_always final_suspend() noexcept { return {}; }
	void unhandled_exception() {}
    };
    HelloWorldCoro(promise_type* p) : m_handle(std::coroutine_handle<promise_type>::from_promise(*p)) {}
    ~HelloWorldCoro() { m_handle.destroy(); }
    std::coroutine_handle<promise_type>      m_handle;
};
HelloWorldCoro print_hello_world()
{
    std::cout << "Coroutine check ";
    co_await std::suspend_always{};
    std::cout << "OK" << std::endl;
}
void conceptEnabled(Iterable auto const& T)
{
    std::cout << "Concept check OK" << std::endl;
}
void conceptEnabled(auto const& T)
{
    std::cout << "Concept check NOK" << std::endl;
}
int main() 
{
    HelloWorldCoro mycoro = print_hello_world();
    mycoro.m_handle.resume();
    mycoro.m_handle();
    auto container = std::vector<int>{};
    conceptEnabled(container);
}
