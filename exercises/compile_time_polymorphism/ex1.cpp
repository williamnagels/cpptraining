#include <global.h>
namespace
{
//TODO: Add a printHelper partial template specialization where T is a pointer type.
//This primary template candidate is OK and should not be changed.
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
    /*ss.clear();
    print(&i, ss);
    ASSERT(ss.str() == "pointer with value 13");*/
}

template <typename T>
void print2(T const& t, std::ostream& os)
{
    //TODO add a compiletime if expression here that will print
    //the asserted output in test_2 correctly if T is a pointer.
    os << t;
}
//GOAL: Solve test_1 with a compile-time if expression. Do not overload function print2.
void test_2()
{
    std::stringstream ss;
    int i = 13;
    print2(i, ss);
    ASSERT(ss.str() == "13");
    //TODO: uncomment the asserts below when the compile-time if logic has been added to print2
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
