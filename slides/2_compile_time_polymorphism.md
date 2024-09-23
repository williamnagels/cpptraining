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
- C++11 -> C++17 era
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
What is the type of result? Type of a and b is deduced independently.

---

# SFINAE
## Substituion Failure Is Not An Error
- The compiler tries to instantiate all templates
- No compilation error, if specialization fails due to failure to instantiate
- Remove candidates from overload resolution set

---
# SFINAE
## SFINAE example
```cpp
template <typename T, typename Enable = typename std::enable_if<!std::is_integral<T>::value>::type>
void print(const T& value) {
    std::cout << "Primary template: " << value << std::endl;
}
template <typename T>
typename std::enable_if<std::is_integral<T>::value>::type print(const T& value) {
    std::cout << "Integral value: " << value << std::endl;
}
```
**::value** is true for std::is_integeral<T> struct if T is integeral.
**::value** static const member, value is known at compile time.

---
# SFINAE 
## Compiler errors
Assume there is no primary candidate implementation
```cpp
<source>:11:10: error: no matching function for call to 'print(double)'
   11 |     print(42.0);      // Works for integers
      |     ~~~~~^~~~~~
<source>:6:59: note: candidate: 'template<class T> typename std::enable_if<std::is_integral<_Tp>::value>::type print(const T&)'
    6 | typename std::enable_if<std::is_integral<T>::value>::type print(const T& value) {
      |                                                           ^~~~~
<source>:6:59: note:   template argument deduction/substitution failed:
<source>: In substitution of 'template<class T> typename std::enable_if<std::is_integral<_Tp>::value>::type print(const T&) [with T = double]':
<source>:11:10:   required from here
   11 |     print(42.0);      // Works for integers
      |     ~~~~~^~~~~~
<source>:6:59: error: no type named 'type' in 'struct std::enable_if<false, void>'
    6 | typename std::enable_if<std::is_integral<T>::value>::type print(const T& value) {
      |

```

---
# SFINAE
## Custom compiler errors on primary candidate
```cpp
template <typename T, typename = typename std::enable_if<!std::is_integral<T>::value>::type>
void print(const T& value) 
{
    static_assert(std::is_integral<T>::value, "we do not support printing non-integral types");
}

template <typename T>
typename std::enable_if_t<std::is_integral<T>::value> print(const T& value) 
{
    std::cout << "Integral value: " << value << std::endl;
}
```

---
# SFINAE
## std::enable_if
```cpp

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };
```
---
# constexpr
## C++ 17
```cpp
template <typename T>
void print(const T& value) 
{
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Integral value: " << value << std::endl;
    } else {
        static_assert(std::is_integral_v<T>, "we do not support printing non-integral types");
    }
}
```
---
# Concepts
## C++20
```cpp
#include <concepts>
template <typename T>
concept Integral = std::is_integral_v<T>;
void print(auto value) 
{
    static_assert(std::is_integral_v<decltype(value)>, "we do not support printing non-integral types");
}
void print(Integral auto value) 
{
    std::cout << "Integral value: " << value << std::endl;
}

```
---
# Concepts
## Compiler errors
Assume there is no primary candidate implementation
```cpp
<source>: In function 'int main()':
<source>:13:10: error: no matching function for call to 'print(double)'
   13 |     print(42.0);      // Works for integers
      |     ~~~~~^~~~~~
<source>:7:6: note: candidate: 'template<class auto:1>  requires  Integral<auto:1> void print(auto:1)'
    7 | void print(Integral auto value)
      |      ^~~~~
<source>:7:6: note:   template argument deduction/substitution failed:
<source>:7:6: note: constraints not satisfied
<source>: In substitution of 'template<class auto:1>  requires  Integral<auto:1> void print(auto:1) [with auto:1 = double]':
<source>:13:10:   required from here
   13 |     print(42.0);      // Works for integers
      |     ~~~~~^~~~~~
<source>:5:9:   required for the satisfaction of 'Integral<auto:1>' [with auto:1 = double]
<source>:5:25: note: the expression 'is_integral_v<T> [with T = double]' evaluated to 'false'
    5 | concept Integral = std::is_integral_v<T>;
      |  

```
---
# Concepts
## Custom concepts
```cpp
template <typename T>
void print(const T& value) requires requires(T a) 
{ 
    std::cout << a 
} 
{
    std::cout << "Value: " << value << std::endl;
}
```
requires clause
requires expression
also works with auto

---
# Concepts
## SFINAE code reuse
```cpp
template <typename T>
void calculate_sum(const T& a, const T& b) requires (std::is_arithmetic_v<T> && requires(T x, T y) { 
    x + y; 
}) 
{
    std::cout << "Sum: " << a + b << std::endl;
}
````
constructs used in SFINAE are reused as concept