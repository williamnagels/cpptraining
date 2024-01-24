#include <global.h>


void move_ex6()
{
  // we learned that we can move data from one object to another
  std::vector<std::string> src1 = { "string one", "string two", "string three", "string four" };
  std::vector<std::string> dst1 = std::move(src1);
  ASSERT(src1.size() == 0);
  ASSERT(dst1.size() == 4);



  // this doesn't work with iterators   
  std::vector<std::string> src2 = { "string one", "string two", "string three", "string four" };
  std::vector<std::string> dst2(std::move(begin(src2)), std::move(end(src2))); 
  ASSERT(src2[0] == "string one");
  ASSERT(dst2[0] == "string one");
  
  // think about why this didn't move the values from src2 to dst2?


  
  /*
   * Luckily there is a way to make it work with move iterator.
   * Dereferencing a move iterator has the equivalent effect of calling
   * std::move on the reference returned by the wrapped iterator, to convert it
   * into an r-value reference.
   */
  std::vector<std::string> src3 = { "string one", "string two", "string three", "string four" };
  std::vector<std::string> dst3(
    std::make_move_iterator(std::begin(src3)),
    std::make_move_iterator(std::end(src3))); 
  ASSERT(src3[0] == "");
  ASSERT(dst3[0] == "string one");
  
  
  /*
   * This also works with STL algorithms
   * uncomment the code below and filter the value 3 from source to the destination vector
   * You can use the copy_if algorithm
   */
  std::vector<std::unique_ptr<int>> src4;
  src4.push_back(std::make_unique<int>(1));
  src4.push_back(std::make_unique<int>(2));
  src4.push_back(std::make_unique<int>(3)); 
  std::vector<std::unique_ptr<int>> dst4;
  
  // ASSERT(dst4.size() == 1);
  // ASSERT(*dst4[0] == 3);
  // ASSERT(src4.size() == 3);
  // ASSERT(src4[2].get() == nullptr);
  
}