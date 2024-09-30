---
marp: true
theme: slide-theme
---
# C++ Training
## Strong types
---
## Strong types
```cpp
void create(double mass, double length);
double mass;
double length;
create(mass, length); 
create(length, mass);
```
- Typically a developer is not interested if an object stores its mass as double, float or int.
- We assume the library works.
---
Type aliases are not enforced, only syntactic. But an improvement nonetheless.
```cpp
using Mass=double;
using Length =double;
void create(Mass mass, Length length);
Mass mass;
Length length;
create(mass, length); 
create(length, length);
```
---
A STRONG type is a type used in place of another type to
carry specific meaning through its name.

---
```cpp
template <typename T, typename Tag>
class StrongType {
public:
    explicit StrongType(T v):_v(std::move(v)){}
private:
    T _v;
};
using Mass = StrongType<double, struct MassTag>;
using Length = StrongType<double, struct LengthTag>;
```cpp
---
- Conversion between units of the same tag can be implemented using std::ratio.
- std::chrono library to support custom ratios as a template parameter.
- There's a compiler in C++, use it as much as you can.
- You can create custom ratios but the SI ratios are provided by the standard library, for example std::kilo
---
```cpp
template <typename T, typename Tag, typename Ratio>
class StrongType {
public:
    explicit StrongType(T v):_v(std::move(v)){}
    template <typename OtherRatio>
    operator StrongType<T, Tag, OtherRatio>() const
    {
        return StrongType<T, Tag, OtherRatio>(_v * Ratio::num / Ratio::den * 
            OtherRatio::den / OtherRatio::num);
    }
    friend std::ostream& operator<<(std::ostream& os, StrongType x)
    {
        os << x._v;
        return os;
    }
private:
    T _v;
};
```
---
## Curiously recurring template pattern (CRTP)
- For some applications it could make sense to add/substract/multiply some types, while for others it may not.
- Some applications may have no use for multiplied masses -kg² - in which case, multiplication should be blocked.
---
```cpp
template <typename StrongType>
struct Crtp
{
    StrongType const& Underlying() const { return static_cast<StrongType const&>(*this);}
};
template <typename StrongType>
struct Addable: Crtp<StrongType>
{
    StrongType operator+(StrongType const& other) const
    {
        return StrongType(this->Underlying().get() + other.get());
    }
};
```
---
```cpp
template <typename T, typename Tag, template<typename> class... Skills>
class StrongType: public Skills<StrongType<T, Tag, Skills...>>...
{
public:
    explicit StrongType(T v):_v(std::move(v)){}

    T get() const{return _v;}
    friend std::ostream& operator<<(std::ostream& os, StrongType x)
    {
        os << x._v;
        return os;
    }
private:
    T _v;
};
using Mass= StrongType<double, struct MassTag, Addable>;
```
Pass derived class as template parameter to base class
---
```cpp
#include "strongType.h"

int main()
{
    Mass x(10); 
    Mass y(4);

    std::cout << x+y<<std::endl;
}
```