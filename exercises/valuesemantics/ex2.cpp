#include <global.h>
#include <thread>

namespace
{
using namespace std::chrono_literals;

std::string s_saved;

class Editor
{
public:
  void append(const std::string &str)
  {
    m_buff.insert(m_buff.end(), str.begin(), str.end());
  }
  
  std::string get() const
  {
    return std::string(m_buff.begin(), m_buff.end());
  }
  
  void save() const
  {
    std::thread t([v=m_buff](){
      std::this_thread::sleep_for(200ms);
      s_saved = std::string(v.begin(), v.end());
    });
    t.detach();
  }

private:
  std::vector<char> m_buff;
};

/**
 * We have a dumb editor that only supports appending
 * test_t is just basic Editor usage as it currently is
 */
void test_1()
{
/*
  Editor e;
  e.append("Hello ");
  e.append("World");
  e.save();
  ASSERT(e.get() == "Hello World");
  ASSERT(s_saved == "Hello World");
*/  
}


/**
 * Now add an undo option to the Editor
 * Uncomment the code below and make it work
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
 * The save takes a long time
 * So we want the save to happen in a different thread
 * Make the save run on a different thread
 * You may need to comment out the code in test_1
 */
void test_3()
{
/*
  Editor e;
  e.append("Hello ");
  auto start = std::chrono::high_resolution_clock::now();
  e.save();
  e.append("World");
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsed = end-start;
  ASSERT(elapsed < 100ms);
  std::this_thread::sleep_for(300ms);
  ASSERT(e.get() == "Hello World");
  ASSERT(s_saved == "Hello ");
*/
}

}
 
void values_ex2()
{
  test_1();
  test_2();
  test_3();
}