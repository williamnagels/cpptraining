#include <global.h>

namespace
{

/* Update AddElement; return true if new element added, else return false
*/
template<typename T>
bool addElement(T& v, int valueToAdd){
  v.push_back(valueToAdd);
  return true;
}

//Container 'v' must contain unique numbers only. The original author created an API : addElement
//to add elements to a container and check if they can be added (are unique) before adding.
//Is std::vector the best container for the job? If using any ascociative container,
//std::unique may no longer compile and the assert has to commented out, why is that?
void test_1()
{
  std::vector<int> v = {1,2 ,7, 8 ,9 ,10};

  ASSERT(addElement(v, 4) == true); 
  //ASSERT(addElement(v, 8) == false);
  ASSERT(std::unique(std::begin(v), std::end(v)) ==std::end(v));
}
//Start sorting the container in ascending order, but stop after 4 elements have been sorted.
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

void cont_ex5()
{
  test_1();
  test_2();

}