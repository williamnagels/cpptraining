#include <global.h>


namespace
{

//Convert container "input" to  container "output" using an algorithm from the stdlib
//you can use an additional temporary container if needed.
//filter out all uneven numbers in the process
//https://en.cppreference.com/w/cpp/algorithm
void test_1()
{
  std::vector<int> input = {4,5,6,8,9};

  std::vector<std::string> output;

  ASSERT(output[1]  == "6");
  ASSERT(std::size(input)  == 5);
}

// skip this exercise for now, come back to it after you completed ex5.cpp
//create a zip iterator to iterate over 2 containers and returns a pair of 2 iterators, each iterator point to an element in the container.

/*using select_access_type_for = std::conditional_t<
    std::is_same_v<Iter, std::vector<bool>::iterator> ||
    std::is_same_v<Iter, std::vector<bool>::const_iterator>,
    typename std::iterator_traits<Iter>::value_type,
    typename std::iterator_traits<Iter>::reference
>;
template <typename T>
using select_iterator_for = std::conditional_t<
    std::is_const_v<std::remove_reference_t<T>>, 
    typename std::decay_t<T>::const_iterator,
    typename std::decay_t<T>::iterator>;
template <typename Iter1, typename Iter2>
class zip_iterator
{
public:
    using value_type = std::pair<select_access_type_for<Iter1>, select_access_type_for<Iter2>>;

    zip_iterator() = delete;

    zip_iterator(Iter1 iter_1_begin, Iter2 iter_2_begin)
    {
    }

    auto operator++() -> zip_iterator& {
    }

    auto operator++(int) -> zip_iterator {
    }

    auto operator!=(zip_iterator const & other) {
    }

    auto operator==(zip_iterator const & other) {
    }

    auto operator*() -> value_type {
    }

private:
    Iter1 m_iter_1_begin;
    Iter2 m_iter_2_begin;
};
template <typename T, typename U>
class zipper
{
public:
    using Iter1 = select_iterator_for<T>;
    using Iter2 = select_iterator_for<U>;

    using zip_type = zip_iterator<Iter1, Iter2>;

    template <typename V, typename W>
    explicit zipper(V && a, W && b)
    {
    }
    auto begin() -> zip_type {
    }
    auto end() -> zip_type {
    }

private:
    T m_a;
    U m_b;
};
template <typename T, typename U>
auto zip(T && t, U && u) {
    return zipper<T, U>{std::forward<T>(t), std::forward<U>(u)};
}*/


void test_2()
{
    const std::vector<std::string> keys{ {"two: ", "five: ", "ten: ", "forty: "} };
    const std::vector<int> values{ {2, 5, 10, 40} };
    std::vector<std::string> c;
    /*for (auto [x, y] : zip(keys, values)) {
        c.push_back(x + std::to_string(y));
    }
    
    ASSERT(output[1]  == "five: 5");
    */

} 
}
 
void cont_ex1()
{
  test_1();
  test_2();
}