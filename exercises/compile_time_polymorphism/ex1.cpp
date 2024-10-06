#include <global.h>
namespace
{

//This primary template candidate is OK and should not be changed.
template <typename T, bool>
struct PrintHelper
{
    static void print(T const& t, std::ostream& os)
    {
        os << t;
    }
};
//TODO: Add a printHelper partial template specialization where T is a pointer type.
//Use the boolean. Set it to true when type T is a pointer type in the function print.
template <typename T>
void print(T const& t, std::ostream& os)
{
    //TODO: Instantiate a different PrintHelper if T is a pointer type.
    //TIP: C++ lib has built-in type checks to see if a type T is a poiner-like type. Take a look at https://en.cppreference.com/w/cpp/meta
    PrintHelper<T, true>::print(t, os);
}

//GOAL: The goal of this exercise is to get some experience with template overloading and template specialization.
//The function print below is called for a value-type 'int' in the uncommented code.
//it will write the value of i to the provided std::stringstream.
//The idea is that in the commented call to print, a pointer is passed as argument. This should cause the compiler to select another candiate from the set.
//That other candidate should write a different string to stringstream to make the assert succeed.
void test_1()
{
    std::stringstream ss;
    int i = 13;
    print(i, ss);
    ASSERT(ss.str() == "13");
    //TODO: uncomment the asserts below when the pointer-like PrintHelper has been implemented
    /*ss = std::stringstream();
    print(&i, ss);
    ASSERT(ss.str() == "pointer with value 13");*/
}

}
void ct_poly_ex1()
{
  test_1();
}
