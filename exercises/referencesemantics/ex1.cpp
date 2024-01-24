#include <global.h>


namespace
{

/***
 * Exercise 1
 * Add move constructors to the following object
 */
struct Object_1
{
  Object_1(const std::string &v) : m_value(v) {}
  Object_1(const Object_1 &obj) : m_value(obj.m_value) {}
    
  std::string m_value;
};


/*
 * How do you know that your code works?
 * Add code here to verify that your new constructors work
 * You have an assert macro available:
 *   ASSERT(1 == 1);
 */
void test_1()
{
/*  std::string str = "obj";
  Object_1 o(std::move(str)); */
}
 
 
/*
 * What do you need to also add support for assignment
 * Uncomment the following code and make them work
 */
void test_2()
{
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