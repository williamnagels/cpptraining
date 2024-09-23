#include <global.h>
namespace
{
// The primary template is OK. No changes required
template <typename, typename = void>
struct is_container : std::false_type {};

// TODO: fix the template specialization of is_container to detect if type T has a
// nested iterator type (check if T::iterator exists)
//template <typename T>
//struct is_container<...> : ... {}

template <typename T>
inline constexpr bool is_container_v = is_container<T>::value;

//GOAL: The goal of this exercise is to implement a is_container check used in SFINAE context
//to remove candidates from the overload resolution set. In this exercise the expression will be 
// created and in the next exercise the compile time expression will be used to remove from the 
// overload resolution set
void test_1()
{
    //TODO: uncomment the asserts below when is_container has been implement for both containers
    //static_assert(is_container_v<std::vector<int>>, "std::vector should be detected as container");
    //static_assert(!is_container_v<int>, "int should not be detected as container");
}
// TODO uncomment the print function below to be only in the set of possible overload candidates
// if T is a container
/*template <typename T>
auto print(T const& , std::ostream& os) -> //TODO fix the return value here
{
    os << "Container: [";
    for (auto const & element : container) 
    {
        os << element << " ";
    }
    os << "]";
}*/

// TODO uncomment the print function below to be only in the set of possible overload candidates
// if T is not a container
/*template <typename T>
auto print(const T& value, std::ostream& os) -> //TODO fix the return value here
{
    os << "Non-container: " << value;
}*/

//GOAL::use the compiletime expressions is_container created in ex1 to select the correct print overload
void test_2()
{
    //TODO: uncomment the asserts below when the print overloads have been fixed to
    //either select the container overload or not.
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

}
void ct_poly_ex2()
{
  test_1();
  test_2();
}