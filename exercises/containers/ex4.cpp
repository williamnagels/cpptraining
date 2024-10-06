#include <global.h>

namespace
{
/*
GOAL: Show customization possibilities of std::sort using a user defined functor.
Sort container 'v' in a descending order. Without any customization std::sort
will sort in an ascending order. Check the declaration of std::sort to figure out how 
std::sort can be customized to sort in a descending orer.
*/
void test_1()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  //TODO: Sort container 'v' in a descending order.
  //TODO: Change the assert below so that it checks if 'v' is sorted in descending order,
  //right now it is checking if 'v' is sorted in ascending order.
  //ASSERT(std::is_sorted(std::begin(v), std::end(v)));
}

/*
GOAL:Check if an integer with value 10 exists in vector 'v' using the lineair search algorithm 'std::find_if'.
Prove a linear search was performed by counting the number of comparisons done while looking for
the number '10'.
std::find_if takes a functor as argument, increase numberOfComparisons each time that functor is invoked.
*/
void test_2()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8, 10};
  std::size_t numberOfComparisons = 0;
  //auto comparator =//
  auto it = v.begin(); //linear search for integer with value 10 using custom comperator
  //TODO: uncomment asserts when the linear search has been implemented.
  //ASSERT(*it == 10); 
  //ASSERT(numberOfComparisons == std::size(v));
}

/*
GOAL:Check if an integer with value 10 exists in vector 'v' using a binary search algorithm.
Prove a binary search was performed by counting the number of comparisons done while looking for
the number '10'.
Look-up a binary search algorithm in the std algorithms. Use the same custom comparison functor 
technique to count the number of comparisons as used in the previous excerise.
*/
void test_3()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8, 10};
  std::size_t numberOfComparisons = 0;
  bool found = true; //binary search for integer with value 10 using custom comperator
  ASSERT(found);
  //TODO: uncomment assert when the binary search has been implemented.
  //ASSERT(numberOfComparisons == std::ceil(std::log2(v.size()) + 1));
}
}

void cont_ex4()
{
  test_1();
  test_2();
  test_3();
}
