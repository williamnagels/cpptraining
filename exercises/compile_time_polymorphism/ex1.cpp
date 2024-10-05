#include <global.h>
namespace
{
//TODO: Add a printHelper partial template specialization where T is a pointer type.
//This primary template candidate is OK and should not be changed.
template <typename T, bool>
struct PrintHelper
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


// Primary candiate is OK. No changes needed.
template <typename T, typename V=void>
struct has_encrypt : std::false_type {};

// TODO: This overload candidate is not selected. Fix the 
// candidate to detect an encrypt function on T then uncomment
// the assert in test_3
template <typename C>
struct has_encrypt<C, typename C::encrypt> : std::true_type {};

// Helper variable template (C++14 onwards). OK. No changes needed
template <typename C>
inline constexpr bool has_encrypt_v = has_encrypt<C>::value;

// Test classes, These should not be modified.
struct A
{
    bool encrypt() { return true;/*dummy implementation*/}
};

//GOAL: The goal of this exercise is to realize the difference between template specialization initalization
//and substitution. Fix the has_encrypt partial specialization so that it properly detects
//any encrypt method on type C. Why is the specialization not selected? Surely it should be
//since class A has an encrypt method and that overload is more specialized.
void test_2()
{
    static_assert(!has_encrypt_v<std::string>, "Detected encrypt on std::string");
    //TODO: uncomment this assert when the has_encrypt specialization has been fixed
    //to detect a member function 'encrypt' on struct A.
    //static_assert(has_encrypt_v<A>, "Did not detect encrypt on A");
}

}
void ct_poly_ex1()
{
  test_1();
  test_2();
}
