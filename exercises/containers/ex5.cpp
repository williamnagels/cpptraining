#include <global.h>

namespace
{

/* Function addElement; 
Add element 'valueToAdd' to container 'v'
Returns true 'valueToAdd' was added to container 'v', false if the element was already in the container 'v'
TODO:Fix the behaviour
*/
template<typename T>
bool addElement(T& v, int valueToAdd)
{
  v.push_back(valueToAdd);
  return true;
}

/*
GOAL: Ascociative containers can implicitly provide sorting behaviour which would otherwise have to be fixed explicitly by 
invoking an std::algorithm.
Container 'v' must always only contain unique numbers, duplicates are not allowed.
The original author created a preliminary API : addElement which should provide this guarantee.
Either change the implementation of addElement to detect a duplicate or change the container type of 'v'. 
In the latter case, ensure that the addElement function can only be used if T is an associative container type.
*/
void test_1()
{
  std::vector<int> v = {1, 2, 7, 8, 9, 10};

  ASSERT(addElement(v, 4) == true); 
  //TODO:uncomment the call to addElement after the addElement implementation has been fixed.
  //ASSERT(addElement(v, 8) == false);
  ASSERT(std::unique(std::begin(v), std::end(v)) ==std::end(v));
}

/*
GOAL: Sort the container 'v' in ascending order. Stop sorting after 4 elements have been sorted.
Do not assume that v always has atleast 4 elements.
*/
void test_2()
{
  std::vector<int> v = {10, 3, 8, 6, 4, 1, 5};
  //TODO: add sort std algorithm invoke.
  
  //TODO: uncomment the asserts below
  /*ASSERT(v[0] == 1);
  ASSERT(v[1] == 3);
  ASSERT(v[2] == 4);
  ASSERT(v[3] == 5);*/
  ASSERT(std::is_sorted(std::begin(v), std::end(v)) == false);

  v = {3, 4, 1};
  //TODO: reinvoke the sort function to sort container 'v'. 
  //Check that it also works on containers with less than 4 integer instances.
  
  /*ASSERT(v[0] == 1);
  ASSERT(v[1] == 3);
  ASSERT(v[2] == 4);*/
  ASSERT(std::is_sorted(std::begin(v), std::end(v)) == true);
}
}

void cont_ex5()
{
  test_1();
  test_2();

}
