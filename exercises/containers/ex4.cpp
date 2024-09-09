#include <global.h>

namespace
{
/*
GOAL: Show customization possibilities of std::sort using a user defined functor.
Sort container 'v' in a descending order. Without any customization std::sort
will sort in an ascending order. Check the signature of std::sort to figure out how 
to sort in a descending order.
*/
void test_1()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  //TODO: sort container 'v' in a descending order.
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
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  int numberOfComparisons = 0;

  //TODO: Correct the arguments of std::find_if to take some functor that counts the number of comparisons.
  //auto it = std::find_if(v.begin(), v.end(), ...);
  //TODO: uncomment the asserts below when the custom functor has been implemented.
  //ASSERT(*it == 10);
  //ASSERT(numberOfComparisons == std::size(v)); //linear scaling
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
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  int numberOfComparisons = 0;
  //TODO: Look for the number 10 using a binary search algorithm in container 'v' 
  //and increase 'numberOfComparisons' everytime a comparison is done.
  //auto it =
  //TODO uncomment asserts when the binary search algorithm has been implemented
  /*
  ASSERT(*it == 10);
  ASSERT(numberOfComparisons== 4);
  */
}
}

void cont_ex4()
{
  test_1();
  test_2();
  test_3();
}
