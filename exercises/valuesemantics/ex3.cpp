#include <global.h>

namespace
{

/**
 * How would you implement a container with value semantics?
 * Implement your own vector like container 'Vec' with value semantics
 * that can be used in the Editor class. You can use a command like interface to print a list of performand actions.
 * when you generate the result, you iterate over all actions chronologically
 */
//class Vec
//{
//}

//class Editor
//{
//public:
//  void append(const std::string &str)
//  {
//    m_buff.insert(m_buff.end(), str.begin(), str.end());
//  }
//  
//  std::string get() const
//  {
//    return std::string(m_buff.begin(), m_buff.end());
//  }
//
//private:
//  Vec m_buff;
//};

/**
 * You should now be able to uncomment the code below
 */
void test_1()
{
/*
  Editor e;
  e.append("Hello ");
  e.append("World");
  ASSERT(e.get() == "Hello World");
*/  
}


/**
 * Now add the undo function, does it make it easier?
 */
void test_2()
{
/*
  Editor e;
  e.append("Hello ");
  e.append("World");
  ASSERT(e.get() == "Hello World");
  e.undo();
  ASSERT(e.get() == "Hello ");
  e.undo();
  ASSERT(e.get() == "");
*/
}

/**
 * Now re-add the threaded save function
 * Did the implementation change compared to ex2?
 */
void test_3()
{
/*
  Editor e;
  e.append("Hello ");
  auto start = std::chrono::high_resolution_clock::now();
  e.save();
  e.append("World");
  ASSERT(e.get() == "Hello World");
  ASSERT(s_saved == "Hello ");
*/
}

}
 
void values_ex3()
{
  test_1();
  test_2();
  test_3();
}