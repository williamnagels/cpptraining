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
 * GOAL: The goal is to understand how internal vtables do not interact well with
 * value semantics
 */
void test_1()
{
  (void) get(Base{});
  // TODO: when uncommenting the assert, it will fail. Why is that ?
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
 * GOAL: The goal is to understand how reference semantics do not work well with
 * value semantics. 
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
  //TODO: why does lifetime extension not work in this specific context of the 'Action' type but works for
  //Config const& g = Config{"action_4"};
}

}
 
void values_ex1()
{
  test_1();
  test_2();
}
