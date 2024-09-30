---
marp: true
theme: slide-theme
---
# C++ Training
## Value semantics
---
## Pass by value
- Copies state of object
- Independent mutable state
```cpp
void do_something(std::vector<int>)
```
---
Move semantics facilitate performant value semantics
```cpp
std::vector<std::string> getPoems()
{
  std::vector<std::string> ans; // imagine ans contains data
  return ans;
}
int main(){
    std::vector<std::string> poems = getPoems();
} 
```
---
## return-value optimization
```cpp
class GFG {
public:
    GFG() { std::cout << "Ctor"<<std::endl; }
    GFG(const GFG&){ std::cout << "Copy Ctor"<<std::endl; }
    GFG(GFG&&){ std::cout << "Move Ctor"<<std::endl; }
};
GFG func()
{
  return GFG(); // RVO example
}
int main()
{
    GFG G = func();
}
---
Ctor
```
---
## Pass by reference
- Copy reference to object state
- Multiple references to same instance possible, race conditions
- Lifetime complexity
```cpp
void do_something(int*, int size)
```
---
- Value semantics are preferred, language is evolving in this direction.
- Nr of bugs, ownership and concurrency have a strong correlation.
- Internal inheritance (e.g. vtable) requires reference semantics out of necessity. value semantics would slice base object.
---
## Library support
- std::variant: closed type, open operation set polymorphism, single dispatch unlike typical double dispatch visitor implementations
- std::optional
- std::expected
- std::any: void* with runtime safety
---
```cpp
#include <iostream>
#include <variant>
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
using VariantType = std::variant<int, std::string>;
std::string get(VariantType v){
    return std::visit(overloaded {
        [](int arg) { return std::to_string(arg); },
        [](const std::string& arg) { return arg;},
    }, v);
}
int main(){

    VariantType v = {"dro"};
    std::cout<<get(v)<<std::endl;
    v={10};
    std::cout<<get(v)<<std::endl;
}
```
---
## Complexity
- Deep copying 
-- Produces a new, independent object; object (member) values are copied
-- std::vector O(N) copies vs O(1) copies when using reference semantics
-- Move semantics, copy elision reduces overhead. 
- Copy on write
-- Shared mutable state accessible from distinct contexts complicates the concurrency model. When should the shared object be deconstructed?
---
exercises/value_semantics/ex1.cpp
exercises/value_semantics/ex2.cpp
exercises/value_semantics/ex3.cpp

---
# value semantics
## Polymorphism and value types
---
## Slicing
- Slicing occurs when vtable info is lost
```cpp
Base& a = get_some_reference();
Base b = a;
```
- Slicing hinders the combination of value semantics and classic inheritance
---
## Value semantics for class hierarchy
Expressive, not loaded with c++ technicalities like references pointers etc.
```cpp
Derived a;
Base &b = a;
auto c = b;
std::vector<Base> v;
v.emplace_pack(Derived1());
v.emplace_pack(Derived2());
v.emplace_pack(Derived3());
```
---
## Goal
We want to generalize the concrete types to a common interface without any vtable like inheritance

---
## Goal
```cpp
int main()
{
  std::vector<Animal> v;
  v.emplace_back(Dog());
  v.emplace_back(Cat());
  for (auto &a : v)
  {
    a.speak();
  }
    
}
```
---
## Type erasure
```cpp
struct Vtable
{
  void (*speak)(void *ptr);
  void (*destroy)(void *ptr);
};
```
- holds function pointers that can operate on objects without knowing their concrete types at compile time
---
```cpp
template <class Concrete>
constexpr Vtable vtable_for
{
  [](void *ptr){ static_cast<Concrete*>(ptr)->speak(); },
  [](void *ptr){ delete static_cast<Concrete*>(ptr); },
};
```
- vtable_for<T> is a variable template. C++14 feature.
- constexpr ensures compile-time instantiation.
---
```cpp
struct Animal
{
  Animal(const T& t);
  ~Animal();
  void speak();
  void *m_concrete;
  Vtable const* m_vtable;
};
```
- Animal stores a void pointer to the concrete implementation
- Memory fragmentation. Pointer chasing.
---
```cpp
template<class T>
Animal(const T& t)
  : m_concrete(new T(t))
  , m_vtable(&vtable_for<T>)
{};
 ~Animal()
  {
    if (m_vtable)
      m_vtable->destroy(m_concrete);
  }

  void speak()
  {
    if (m_vtable)
      m_vtable->speak(m_concrete);
  }
```
- Templated constructor, instantiates vtable_for templated constexpr variable
---
```cpp
struct Dog
{
  void speak() { std::cout << "Woof\n"; }
};

struct Cat
{
  void speak() { std::cout << "Meow\n"; }
};
```
---
## Other use-cases
- You can’t easily extend a class with interfaces
- Cleanup class hierarchy
- Template cleanup
- ...