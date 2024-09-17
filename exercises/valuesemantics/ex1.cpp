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
 * GOAL: The goal is to understand how using both internal inheritance and value semantics
 * leads to unexpected behaviour. 
 */
void test_1()
{
  (void) get(Base{});
  // TODO: The assert fails when it is uncommented. Why is that?
  // What can you change to the function 'get' to make the assert succeed?
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
 * GOAL: A common issue when mixing value and reference semantics is that the explicit nature of value semantics 
 * might lead to lifetime problems. Lifetime extension can help prevent some issues, 
 * but the feature is too limited in scope to prevent all issues.
 */
void test_2()
{
  //TODO: uncomment the asserts below. The code will break. Why is that?
  /*
  std::vector<Action> v;
  v.emplace_back(Config{"action_1"});
  v.emplace_back(Config{"action_2"});
  v.emplace_back(Config{"action_3"});
  ASSERT(v[0].perform() == "action_1");
  ASSERT(v[1].perform() == "action_2");
  ASSERT(v[2].perform() == "action_3");
 */
  //TODO: why does lifetime extension not work in this specific context of the 'Action' type but does works for
  //Config const& g = Config{"action_4"};
}

}
 
void values_ex1()
{
  test_1();
  test_2();
}
