#include <global.h>

namespace
{

struct Object_1
{
  Object_1(const std::string &v) : m_value(v) {}
  Object_1(const Object_1 &obj) : m_value(obj.m_value) {}
  //TODO: Implement constructors.
  std::string m_value;
};

/* GOAL: Get familiar with move semantics by adding a move constructor to the Object_1 class.
 * Add runtime asserts to verify that the move constructor is invoked.
 * An ASSERT macro is provided by global.h. Take a look at test_2 for assert demo and inspiration on how to use it.
 * TIP: a moved from std::string is empty.
 */
void test_1()
{
  //TODO: uncomment these lines when the move constructor is implemented
  /*
  std::string str = "obj";
  Object_1 o(std::move(str)); 
  */
  //TODO: add assert to verify that move constructor is invoked.
}
/* GOAL: Get familiar with move semantics by add a move assignment constructor to the 
 * Object_1 class.
 */
void test_2()
{
  //TODO: uncomment these lines when the move assignment constructor is implemented.
  /*
  Object_1 obj1("obj1");
  Object_1 obj2("obj2");
  obj1 = std::move(obj2);
  ASSERT(obj2.m_value.size() == 0);
  ASSERT(obj1.m_value == "obj2");
  */
}

} 
 
void move_ex1()
{
  test_1();
  test_2();
}
