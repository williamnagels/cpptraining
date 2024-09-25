#include <global.h>
namespace
{
constexpr std::size_t N = 128; 
//TODO: Uncomment and fix the concept below. A SmallType is a type with a size less than N.
//A large Type is any type that is not a small type.
/*
template <typename T>
concept SmallType = 
template <typename T>
concept LargeType =
*/
//TODO: Constrain this zip overload so that it is only used for small types.
template <typename T>
bool zip(T const& obj)
{
  //Imagine some zipping algorithm that works well on small types
  return true;
}
//TODO. provide another overload for zip. That overload shall be constrained on LargeType and returns false.

//These types are OK and should not updated.
struct Small 
{
    char b;
};

struct Large
{
    char data[N+1]; // Larger than N bytes
};

/* GOAL: Get some concepts experience by implementing the LargeType and SmallType concepts above.
Constrain both overloads of zip(one still has to be added) with these concepts. The zip overload 
constrained for large types returns false, while the zip overload for small types returns true.
While you could obviously overload the function Zip on Small and Large this is not the point, the idea
is that any type could be passed to zip() and the correct algorithm is chosen automatically depending
on the size of type T.
*/
void test_1()
{
  Small small;
  Large large;
  ASSERT(zip(small) == true);
  //TODO: uncomment the assert below afer the SmallObject and LargeType concepts have been defined
  //and the overloaded zip function has been provided.
  //ASSERT(zip(large) == false);
}
}
void ct_poly_ex3()
{
  test_1();
  test_2();
}
