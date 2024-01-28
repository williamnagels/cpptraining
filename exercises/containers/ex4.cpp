#include <global.h>

namespace
{
//sort from large to small
void test_1()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  //ASSERT(std::is_sorted(std::begin(v), std::end(v)));
}

//Check if element 10 is present using std::find_if linear search
//count the number of comparisons done to find nr 10.
//std::find_if takes a functor as argument, increase numberOfComparisons 
//each time the functor is invoked.
//since it is the last element, expect N comparisons.
void test_2()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  int numberOfComparisons = 0;

  //auto it = std::find_if(v.begin(), v.end(), myFunctor);
  //ASSERT(*it == 10);
  //ASSERT(nums== std::size(v)); //linear scaling
}

//Do the same thing. Search for element with value 10. but
//do a binary search. Compare the number of comparisons and
//understand the difference.
void test_3()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  int numberOfComparisons = 0;

  //auto it = std::find_if(v.begin(), v.end(), myFunctor);
  //ASSERT(*it == 10);
  //ASSERT(nums== 4);
}
}

void cont_ex4()
{
  test_1();
  test_2();
  test_3();
}