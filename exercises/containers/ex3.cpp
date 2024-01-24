#include <global.h>

namespace
{

template<typename T>
bool addElement(T& v, int valueToAdd){
  v.push_back(valueToAdd);
  return true;
}

//v is supposed to be a container of unique nrs. the original author created an addElement
//function which you are supposed to use iso push_back. Fix the code by making changes to addElement and the
//container type
void test_1()
{
  std::vector<int> v = {1,2 ,7, 8 ,9 ,10};

  ASSERT(addElement(v, 4) == true);
  //ASSERT(addElement(v, 8) == false);
}
//Given a vector of integers v, write a test function that verifies the following:
//The first four elements of v are sorted in ascending order, while the remaining elements are not necessarily sorted.
//You may assume that the original vector v has at least four elements.
void test_2()
{
  std::vector<int> v = {10,3,8,6,4,1,5};

  /*ASSERT(v[0] == 1);
  ASSERT(v[1] == 3);
  ASSERT(v[2] == 4);
  ASSERT(v[3] == 5);*/
  ASSERT(std::is_sorted(std::begin(v), std::end(v)) == false);

}
}

void cont_ex3()
{
  test_1();
  test_2();

}