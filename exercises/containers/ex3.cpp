#include <global.h>

namespace
{
//GOAL: Filter out all uneven integers from container 'input', convert
//the remaining integers to instances of type std::string and append them 
//to container 'output'.
//
//It is possible to do this using 1 algorithm from https://en.cppreference.com/w/cpp/algorithm
void test_1()
{
  std::vector<int> input = {4,5,6,8,9};
  std::vector<std::string> output;
  //TODO: Filter out uneven elements from container 'input' and push the remaining vector to 'output'
  //ASSERT(output[1]  == "6");
  //ASSERT(std::size(input)  == 5);
}
}
 
void cont_ex3()
{
  test_1();
}
