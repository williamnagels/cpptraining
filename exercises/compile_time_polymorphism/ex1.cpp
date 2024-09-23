#include <global.h>
namespace
{
//TODO: add a printHelper template specialization that is only instantiated when
//the type to print is a pointer
template <typename T, bool>
struct PrintHelper<T>
{
    static void print(T const& t, std::ostream& os)
    {
        os << t;
    }
};

template <typename T>
void print(T const& t, std::ostream& os)
{
    //TODO: Instantiate another PrintHelper if T is a pointer type.
    //TIP: check the list of possibilities at https://en.cppreference.com/w/cpp/meta
    PrintHelper<T, true>::print(t, os);
}
//GOAL: The goal of this exercise is to get some experience with template overloads.
//The idea is that some print function takes either a value or a pointer type. it prints the
//the value of the value type and print the value to which the pointer refers.
//To make this work the print() method should instantiate the correct PrintHelper type.
//A new printHelper type needs to be added to work with pointers only. it does not exist right now.
void test_1()
{
    std::stringstream ss;
    int i = 13;
    print(i, ss);
    ASSERT(ss.str() == "13");
    //TODO: uncomment the asserts below when the pointer overload has been implemented
    /*ss.clear();
    print(&i, ss);
    ASSERT(ss.str() == "pointer with value 13");*/
}
//TODO: private another overload for a pointer type T, check the output
//of the print in the actual test_2 function. This function is OK and
//should not be changed.
static void print_impl(T const& t, std::ostream& os, std::true_type)
{
    os << t;
}
template <typename T>
void print2(T const& t, std::ostream& os)
{
    //TODO add a compiletime if expression here that will print
    //the asserted output in test_2 correctly if T is a pointer.
    os << t;
}
//GOAL: Solve test_1 with a compile-time if instead of template overloads
//only print2 should be changed for this.
void test_2()
{
    std::stringstream ss;
    int i = 13;
    print2(i, ss);
    ASSERT(ss.str() == "13");
    //TODO: uncomment the asserts below when the compiletime if has been added.
    /*ss.clear();
    print2(&i, ss);
    ASSERT(ss.str() == "pointer with value 13");*/
}

}
void ct_poly_ex1()
{
  test_1();
  test_2();
}
