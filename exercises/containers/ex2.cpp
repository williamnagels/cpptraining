#include <global.h>

namespace
{
//sort from large to small
void test_1()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  ASSERT(std::is_sorted(std::begin(v), std::end(v)));
}

//Check if element 10 is present using std::find_if
void test_2()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  int nums = 0;
  auto comperator = [&nums](auto a, auto b) -> bool{
    nums ++;
    return a == b;  
  };


  //ASSERT(nums== std::size(v));
}

//Check if element 10 is present using binary search
void test_3()
{
  std::vector<int> v = {4, 3, 6, 2, 9, 8,10};
  int nums = 0;
  auto comperator = [&nums](auto a, auto b) -> bool{
    nums ++;
    return a < b;  
  };


  //ASSERT(nums== 4);
}
}

void cont_ex2()
{
  test_1();
  test_2();
}