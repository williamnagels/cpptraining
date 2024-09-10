#include <global.h>

namespace
{
//GOAL: Filter out all uneven integers from container 'input' convert
//the remaining integers to instances of type std::string and append them 
//to container 'output'.
//
//Use an additional temporary container if you must, but it is possible to 
//do this using 1 algorithm from https://en.cppreference.com/w/cpp/algorithm
void test_1()
{
  std::vector<int> input = {4,5,6,8,9};
  std::vector<std::string> output;
  //TODO: filter out uneven elements from container 'input' and push the result to vector 'output'
  // ASSERT(output[1]  == "6");
  // ASSERT(std::size(input)  == 5);
}
}
 
void cont_ex3()
{
  test_1();
}
