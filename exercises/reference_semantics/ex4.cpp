#include <global.h>

namespace
{

//TODO: Fix the Object class so that the commented assert in 'test_1' compiles.
template <typename T>
struct Object
{
  Object(T &&t) : m_value(std::forward<T>(t)) {}
  
  T m_value;
};


/*
GOAL: Fix the constructor in class Object<T> so that the commented assert in 'test_1' compiles.
TIP: the constructor of 'Object' must accept l-value and r-value references. Either make 2 overloads or use
universal references. Remove the constructor from the overload set if the type passed in the constructor is not equal to T.
The type passed in the constructor may be qualified with const or reference.
*/
void test_1()
{
  std::unique_ptr<int> ptr = std::make_unique<int>(5);
  auto obj1 = Object<decltype(ptr)>(std::move(ptr));
  
  std::string v2 = "2";
  auto obj2 = Object<decltype(v2)>(std::move(v2));
  
  //TODO: uncomment this assert when Object class has been fixed.
  /*
  std::string v3 = "3";
  auto obj3 = Object<decltype(v3)>(v3);
  */
}

}

void move_ex4()
{
  test_1();
}
