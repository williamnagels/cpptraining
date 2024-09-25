---
marp: true
theme: slide-theme
---
# C++ Training
## Compile-time polymorphism
---
# What is Compile-Time Polymorphism?

- Compile-time type erasure
- **Templates**
- Avoid code duplication
- Meta-programming; type inspection
---
# Key features
- C++99/03
    - Class/Function templates
    - Template specialization
- C++11 -> C++17 era
    - Auto keyword
    - if constexpr
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
#include <iostream>
template <typename T, typename S>
void print(T const& value, S& stream)
{
    stream << "Value: " << value << std::endl;
}
template <typename S>
void print(std::string const& value, S& stream)
{
    stream << "std::string specialization: " << value << std::endl;
}
int main()
{
    print(123, std::cout);
    print("combust", std::cout);
}
```
What is the output of the print statements?

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
Same issue as previous slide

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
What is the type of 'result'? Type of a and b is deduced independently.

---

# SFINAE
## Substitution Failure Is Not An Error
- Create a set of all possible candidates includes non-specialized
- Substitute type
- No compilation error, if substitution fails
- Remove candidates from overload resolution set
---
# SFINAE
## Overload resolution set
```cpp
template <typename T, typename Stream>
auto print(T const& value, Stream& stream) {
    stream << "std::string specialization: " << value << std::endl;
    return std::begin(value);
}
template <typename Stream>
void print(double value, Stream& stream) {
    stream << "Value: " << value << std::endl;
}
int main() {
    print(123, std::cout);
    print(std::string("combust"), std::cout);
}
```
---
## Overload resolution set
Removed primary candiate from set. This compiles.
```cpp
template <typename T, typename Stream>
auto print(T const& value, Stream& stream) -> T::iterator
{
    stream << "std::string specialization: " << value << std::endl;
    return std::begin(value);
}
template <typename Stream>
void print(double value, Stream& stream)
{
    stream << "Value: " << value << std::endl;
}
```
---
## Overload resolution set
- SFINAE only works in the 'immediate' context.
- Generally, think arguments and return type.
- Body of a function is NOT the immediate context.
Fails to compile - no SFINAE:
```cpp
template <typename T, typename Stream>
auto print(T const& value, Stream& stream)
{
    typename T::iterator begin; // NOT the immediate context
    stream << "std::string specialization: " << value << std::endl;
    return std::begin(value);
}
```
---
# SFINAE
## standard library
```cpp
namespace std 
{
    //Primary template for enable_if, does not contain type T
    template<bool B, class T = void>
    struct enable_if {};
    //Specialization for B==True, does encapsulate type T.
    template<class T>
    struct enable_if<true, T> { typedef T type; };   
}
```
---
# SFINAE
## std::enable_if example
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
**::value** static const member -> value is known at compile time.

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
Assume more than 1 specialization, but for slide reasons there is only 1 specialization.
```cpp
template <typename T, typename = typename std::enable_if<!std::is_integral<T>::value>::type>
void print(T const& value) 
{
    static_assert(false, "Unsupported print operation");
}

template <typename T>
typename std::enable_if_t<std::is_integral<T>::value> print(T const& value) 
{
    std::cout << "Integral value: " << value << std::endl;
}
```
---
# constexpr
## C++ 17
```cpp
template <typename T>
void print(T const& value) 
{
    if constexpr (std::is_integral_v<T>) 
    {
        std::cout << "Integral value: " << value << std::endl;
    } 
    else 
    {
        static_assert(false, "Unsupported print operation");
    }
}
```
---
# constexpr
```cpp
template <typename T>
void print(T const& value) 
{
    if constexpr (value == 124) 
    {
        std::cout << "Integral value: " << value << std::endl;
    } 
    else 
    {
        static_assert(false, "Unsupported print operation");
    }
}
```
```
<source>:5:5: error: 'value' is not a constant expression
    5 |     if constexpr (value == 124)
      |     ^
```
---
# Concepts
## C++20
```cpp
#include <concepts>
template <typename T>
concept Integral = std::is_integral_v<T>;
void print(auto const& value) 
{
    static_assert(std::is_integral_v<decltype(value)>, "Unsupported print operation");
}
void print(Integral auto const& value) 
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
void print(T const& value) requires requires(T a) {  std::cout << a } 
{
    std::cout << "Value: " << value << std::endl;
}
```
requires clause
requires expression
also works with auto

---
# Concepts
## Combination of requires and predicate
```cpp
template <typename T>
void calculate_sum(T const& a, T const& b) requires (std::is_arithmetic_v<T> && requires(T x, T y) { 
    x + y; 
}) 
{
    std::cout << "Sum: " << a + b << std::endl;
}
```
---
# Concepts
## Constrained class template
```cpp
template <typename T>
concept Addable = requires(T a, T b)
{
    { a + b } -> std::same_as<T>;
};
template <Addable T>
struct Calculator 
{
    Calculator(T value) : m_value(value) {}
private:
    T m_value;
};
```
