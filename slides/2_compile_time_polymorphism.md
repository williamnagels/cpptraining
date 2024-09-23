---
marp: true
theme: slide-theme
---
# C++ Training
## Compile-time polymorphism
---
# What is Compile-Time Polymorphism?

- Different types to be treated as the same through a common interface.
- During compilation
- **Templates**
- Avoiding code duplucation.
- Meta-programming; type inspection - compile-time logic
---
# Key features
- C++99/03
    - Class/Function templates
    - Template specialization
- C++11
    - Auto keyword
    - SFINAE
- C++20
    - Concepts
---
# Function template
```cpp
template <typename T>
T add(T const& a, T const& b) 
{
    return a + b;
}
int main() 
{
    int result = add(5, 10);   // 5 is int
    double res = add(5.5, 2.3); // 5.5 is double
}
```
- Does not promote or demote the built-in type. No casting
---
# Class template
```cpp
template <typename T, int N>
class Array 
{
public:
    T data[N];
    T& operator[](int index)
    {
        return data[index]; 
    }
};

int main() 
{
    Array<int, 10> intArray;
    Array<double, 5> dblArray;
}
```
- Size of the array is part of type.
---
# Function template specialization
```cpp
template <typename T>
void print(T const& value)
{
    std::cout << "Value: " << value << std::endl;
}
template <>
void print(std::string const& value)
{
    std::cout << "C-String: " << value << std::endl;
}
int main()
{
    print(123);
    print("Hello, world!");
}
```
---
# C++20 - auto keyword 1/2
```cpp
auto /*C++14 auto*/ add(auto const& a, auto const& b /*C++20 auto*/)
{
    return a + b;
}
auto add(std::string const& a, std::string const& b) 
{
    return std::stoi(a) + std::stoi(b);
}
int main() 
{
    auto result = add(5, 10); //C++11 auto
    auto res = add("1", "2");
}
```
Overload resolution prefers type with least casts or type errasure

---
# C++20 - auto keyword 2/2
```cpp
#include <iostream>
auto add(auto const& a, auto const& b) 
{
    return a + b;
}
int main() 
{
    auto result = add(6.6, 10);
    std::cout << typeid(result).name() << std::endl;
}
```
What is the type of result? Each auto is deduced independently.

---

# SFINAE
## Substituion Failure Is Not An Error
<!--- Remove candidates from overload resolution set
- Works with auto and templates variants of type errasure. -->
- The compiler tries to instantiate a template
- No compilation error, if specialization fails due to failure to instantiate

---
# SFINAE
## SFINAE example
```cpp
template <typename T, typename Enable = void>
void print(const T& value) {
    std::cout << "Primary template: " << value << std::endl;
}
template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type print(const T& value) {
    std::cout << "Integral value: " << value << std::endl;
}
```
**::value** does not exist on std::is_integeral<T> struct it T is not integeral.
Overload only matches for all types that are considered 'integeral'

---
# SFINAE
## Custom compiler errors on primary candidate
```cpp
template <typename T, typename Enable = void>
void print(const T& value) 
{
    static_assert(false, "we do not support printing non integers");
}
template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type print(const T& value) 
{
    std::cout << "Integral value: " << value << std::endl;
}
```
