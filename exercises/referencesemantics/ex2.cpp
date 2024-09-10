#include <global.h>

namespace
{

// This class does not need to be modified for the asserts in 'test_1' to succeed.
// Only function 'split' and 'test_1' have to be modified.
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



/*
'split' splits a vector 'vec' passed as argument and returns 2 new vectors.
One vector contains all Object1 instances which have an 'even' value in data member 'm_value'.
The other newly created vector contains a vector with all Object1 instances which have an 'uneven' value in data member 'm_value'
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
/* 
GOAL: To goal of this excercise is to show how move semantics may ellide copies.
In function 'split' and function 'test_1' there are a lot of expressions that cause copies.
Not all copies are needed. Investigate which copies can be removed and which copies can be 
replaced by moves.
*/
void test_1()
{
  std::vector<Object1> v;
  for (uint64_t i = 1; i <= 10; ++i)
  {
    v.push_back(Object1(i));
  }
  auto value = split(v);

  // These prints might help you debug:
  std::cout << "constructs: " << Object1::s_constructs << "\n";
  std::cout << "moves: " << Object1::s_moves << "\n";
  std::cout << "copies: " << Object1::s_copies << "\n";
  std::cout << "evens: " << value.first.size() << "\n";
  std::cout << "unevens: " << value.second.size() << "\n";

  // TODO: uncomment these lines. Fix the code in 'test_1' and 'split' so that the asserts succeed.
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
