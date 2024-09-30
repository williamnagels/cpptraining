---
marp: true
theme: slide-theme
---
# C++ Training
## Containers
---
TODO insert complexity scaling image here
---
# Time complexity
- O(1). “Regardless of #elements, operation takes constant time”
- O(n). Loop over each item and do an operation, print all items
- O(log(n)+c). Base 2. Binary search 
-- Size 7. Worst case search complexity log(7) -> 3

---
TODO insert binary search image here

---
TODO insert complexity image here

---

## std::array vs std::vector
- std::array. Fixed size memory. could be stack. could be heap.
- std::vector. heap allocates. Dynamic Size
- Back insert/erase -> N operations may be needed if not back position.
---
## vector resize
```cpp
void print(auto const& x)
{
    std::cout << "capacity: "<< x.capacity() << " "<< &x[0]<<std::endl;
}
int main()
{
    std::vector<int> v;

    for(int i = 0; i< 10; i++)
    {
        v.push_back(i);
        print(v);
    }
}
```
---
- If capacity grows the base memory address changes
- Expensive operation
```cpp
Program stdout
capacity: 1 0xa53eb0
capacity: 2 0xa54ee0
capacity: 4 0xa53eb0
capacity: 4 0xa53eb0
capacity: 8 0xa54f00
capacity: 8 0xa54f00
capacity: 8 0xa54f00
capacity: 8 0xa54f00
capacity: 16 0xa54f30
capacity: 16 0xa54f30
```
---

## std::list / std::forward_list
- Double linked list (forward and backwards traversable)
- Search is linear in complexity even when sorted.
- Useful for stacks, list priorities etc.
- No random access (linear when not using iterator)
---
## std::deque
- Hybrid between std::vector and std::list
- Linked list like structure, each node(bucket) of the list has the capacity to store more than 1 element.
- The O(1) access complexity of std::deque is paid for by increasing space complexity.
---
## std::deque
```cpp
template<
    class T,
    class Allocator = std::allocator<T>
> class deque;
```
- Bucket size ?
- Larger objects (e.g. sizeof(T) == sizeof(Bucket)), std::deque turns into a convoluted std::list, which may perform worse if random access is not a requested feature
```cpp
#ifndef _GLIBCXX_DEQUE_BUF_SIZE
#define _GLIBCXX_DEQUE_BUF_SIZE 512
#endif

_GLIBCXX_CONSTEXPR inline size_t
__deque_buf_size(size_t __size)
{ 
    return (__size < _GLIBCXX_DEQUE_BUF_SIZE ? size_t(_GLIBCXX_DEQUE_BUF_SIZE / __size) : size_t(1)); 
}
```
---
## std::map
- std::set is an std::map where the value is also used as key/comparator implementation
- log(n) across the board -> rb tree
- Not contiguous in memory
---
## rb-trees
- Left child node is smaller than parent node
- Right child node is larger than parent node
- Self-balancing on insert/erase
- Finding an element -> half of the tree can be ignored
- log(n) search property. 
- Rebalancing the tree is log(n)
---
## std::unordered_map/std::unordered_set
- O(1) achieved by hashing. Hashing can be expensive
- If you need to store unique elements and care about order, use std::set.
- Store unique elements and do not care about order use set::unordered_set.
---

## std::unordered_map/std::unordered_set
```cpp
template<
    class Key,
    class Hash = std::hash<Key>, // find bucket
    class KeyEqual = std::equal_to<Key>, //find element in bucket
    class Allocator = std::allocator<Key>
> class unordered_set;

template<
    class Key,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<Key>
> class set;
```
---
# Space complexity
- std::vector: 8 bytes - contigious
- std::deque: size of block - not contigious
- std::list: 24 bytes - not contigious
- std::set: 8 + 3 * 8 + 8 - not contigious

---
```cpp
template <typename T>
class MyAllocator 
{
public:
    using value_type = T; //needed by std::set
    T* allocate(std::size_t n) {
        std::cout << "Allocating: " << n * sizeof(T) << " bytes"<<std::endl;
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }
    void deallocate(T* p, std::size_t n) {
        ::operator delete(p);//TODO: is this correct ? 
    }
};
int main() {
    using MySet = std::set<uint64_t, std::less<uint64_t>, MyAllocator<uint64_t>>;
    MySet mySet;
    mySet.insert(20);
}
https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.1/structstd_1_1___rb__tree__node.html
---
Allocating: 40 bytes
```
---
```cpp
template <typename T>
struct CustomAllocator {
    using value_type = T;
    CustomAllocator() noexcept = default;
    template <typename U>
    CustomAllocator(const CustomAllocator<U>&) noexcept {}
    T* allocate(std::size_t n) {
        std::cout << "Allocating " << this << " name="<< typeid(T).name() 
		   <<" n="<< n << " T="<< sizeof(T) << std::endl;
        if (auto p = static_cast<T*>(std::malloc(n * sizeof(T)))) {
            return p;
        }
        throw std::bad_alloc();
    }
    void deallocate(T* p, std::size_t) noexcept {
        std::cout << "Deallocating" <<std::endl;
        std::free(p);
    }
};
```
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