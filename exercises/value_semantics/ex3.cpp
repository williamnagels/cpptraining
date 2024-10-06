#include <global.h>
#include <any>

namespace
{

// class MyAny
// {
// TODO: Delete the l-value copy constructor.
// TODO: Implement an r-value move constructor.
// TODO: Implement a templated constructor that accepts any type T.
// TODO: Implement a comparison operator that check if the type and value of some MyAny instance is equal to another MyAny instance.
// };

/**
 * GOAL: Recreate a simplified version of `std::any`. `std::any` allows storage of any type with full type erasure,
 * and could conceptually be compared to a smart void pointer. std::any provides functionality to query the type of the value stored
 * within.
 * 
 * Note: Only the behavior required to make the test succeed will be implemented, not the full `std::any` functionality.
 * Comparison support will have to be added to make the asserts work. `std::any` does not support direct comparison of contained values.
 */
void test_1()
{
//TODO: uncomment these asserts when the MyAny class has been implemented.
/*
  MyAny i1 = 1;
  MyAny i2 = 1;
  MyAny s1 = std::string("string");
  MyAny s2 = std::string("string");
  MyAny s3 = std::string("string2");
  ASSERT(i1 == i2);
  ASSERT(s1 == s2);
  ASSERT(s1 != s3);
  ASSERT(i1 != s1);
  ASSERT(i2 != s2);
*/
}

}
 
void values_ex3()
{
  test_1();
}
