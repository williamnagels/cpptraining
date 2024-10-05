#include <global.h>
namespace
{
// The primary template candidate is OK. No changes required
template <typename, typename = void>
struct is_container : std::false_type {};

// TODO: fix the template specialization of is_container to detect if type T has a
// nested iterator type (TIP: check if T::iterator is a valid type)
/*
template <typename T>
struct is_container<...> : ... { }
*/

// Should not be changed.
template <typename T>
inline constexpr bool is_container_v = is_container<T>::value;

//GOAL: The goal of this exercise is to implement a is_container check that will be used in a SFINAE context.
//In this exercise the expression will be created and in the next exercise the compile time expression will be used to remove candidates from the 
//overload resolution set
void test_1()
{
    //TODO: uncomment the asserts below when the is_container predicate has been implemented
    //static_assert(is_container_v<std::vector<int>>, "std::vector should be detected as container");
    //static_assert(!is_container_v<int>, "int should not be detected as container");
}

// TODO: Use SFINAE to remove this print overload candidate from the set if T is not a container.
/*
template <typename T>
auto print(T const& , std::ostream& os) -> //TODO use SFINAE on return value here
{
    os << "Container: [";
    for (auto const & element : container) 
    {
        os << element << " ";
    }
    os << "]";
}
*/

// TODO: Use SFINAE to remove this print overload candidate from the set if T is a container.
/*
template <typename T>
auto print(T const& value, std::ostream& os) -> //TODO use SFINAE on return value here
{
    os << "Non-container: " << value;
}
*/

//GOAL: Use the is_container predicate created for test_1 to select the correct print function in this test.
void test_2()
{
    //TODO: uncomment the asserts when the overloaded print functions above have been updated.
    {
        std::stringstream ss;
        std::vector<int> input = {1, 2, 3, 4};
        //print(input, ss);
        //ASSERT(ss.str() == "[1, 2, 3, 4]");
    }
    {
        std::stringstream ss;
        int input = 13;
        //print(input, ss);
        //ASSERT(ss.str() == "13");
    }
}
template <typename T>
void print2(T const& t, std::ostream& os)
{
    //TODO add a compiletime if expression here that will print
    //the asserted output in test_2 correctly if T is a pointer.
    os << t;
}
//GOAL: Solve ex1.cpp/test_1 with a compile-time if expression. Do not overload function print2.
void test_3()
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
void ct_poly_ex2()
{
  test_1();
  test_2();
  test_3();
}
