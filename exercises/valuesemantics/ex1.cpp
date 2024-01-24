#include <global.h>

namespace
{

struct Base
{
  virtual int get() const { return 0; };
};

struct Derived : public Base
{
  Derived(int a) : i(a) {}
  virtual int get() const override { return i; }
  int i;
};

int get(const Base b)
{
  return b.get();
}

/**
 * Uncomment the code in test_1
 * Why does the test fail?
 * What do we need to do to solve this?
 */
void test_1()
{
  (void) get(Base{});
  // Derived d(1);
  // ASSERT(get(d) == 1);
}


struct Config
{
  std::string name;
};

struct Action
{
  Action(const Config &c)
    : m_c(c)
  {}
  
  std::string perform()
  {
    return m_c.name;
  }
  
  const Config &m_c;
};


/**
 * Uncomment the code in test_2 and run it.
 * 
 * What went wrong?
 * What do you need to do to fix this?
 */
void test_2()
{
/*
  std::vector<Action> v;
  v.emplace_back(Config{"action_1"});
  v.emplace_back(Config{"action_2"});
  v.emplace_back(Config{"action_3"});
  ASSERT(v[0].perform() == "action_1");
  ASSERT(v[1].perform() == "action_2");
  ASSERT(v[2].perform() == "action_3");
*/
}

}
 
void values_ex1()
{
  test_1();
  test_2();
}