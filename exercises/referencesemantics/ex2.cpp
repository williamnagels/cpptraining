#include <global.h>

namespace
{

/**
 * You do not need to modify this object
 */
struct Object1
{
  Object1(uint64_t v) : m_value(v) { ++s_constructs; }
  Object1(Object1 &&o) : m_value(o.m_value) { ++s_moves; }
  Object1(const Object1 &o) : m_value(o.m_value) { ++s_copies; }
  
  uint64_t m_value;
  
  static uint64_t s_constructs;
  static uint64_t s_moves;
  static uint64_t s_copies;
};

uint64_t Object1::s_constructs = 0;
uint64_t Object1::s_moves = 0;
uint64_t Object1::s_copies = 0;



/**
 * Uncomment the ASSERTs in "test_1" and 
 * modify the function "split" and "test_1" so the asserts pass
 */

std::pair<std::vector<Object1>, std::vector<Object1>> split(const std::vector<Object1> vec)
{
  std::vector<Object1> even;
  std::vector<Object1> uneven;
  for (const auto o : vec)
  {
    if (o.m_value % 2 == 0)
      even.push_back(o);
    else
      uneven.push_back(o);
  }
  return {even, uneven};
}

void test_1()
{
  std::vector<Object1> v;
  for (uint64_t i = 1; i <= 10; ++i)
  {
    v.push_back(Object1(i));
  }
  auto value = split(v);

  // these lines might help you debug
  
  std::cout << "constructs: " << Object1::s_constructs << "\n";
  std::cout << "moves: " << Object1::s_moves << "\n";
  std::cout << "copies: " << Object1::s_copies << "\n";
  std::cout << "evens: " << value.first.size() << "\n";
  std::cout << "unevens: " << value.second.size() << "\n";
  

  // uncomment these line, you do not need to modify them
  /*ASSERT(Object1::s_constructs == 10);
  ASSERT(Object1::s_moves == 10);
  ASSERT(Object1::s_copies == 0);
  ASSERT(value.first.size() == 5);
  ASSERT(value.second.size() == 5);*/
  
}


}

void move_ex2()
{
  test_1();
}