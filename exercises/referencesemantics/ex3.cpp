#include <global.h>

/**
 * Uncomment the code in "test_1" and change the "builder" function to make it work
 */


namespace
{

struct Object
{
  Object(const std::string &s) : m_value(s) {}
  Object(std::string &&s) : m_value(std::move(s)) {}
  Object(std::unique_ptr<int> &&i) : m_value(std::move(i)) {}
  
  std::variant<std::string, std::unique_ptr<int>> m_value;
};


Object builder(const std::string &v)
{
  return Object(v);
}


void test_1()
{
  std::string v1 = "1";
  auto obj1 = builder(v1);
  ASSERT(std::get<std::string>(obj1.m_value) == "1");
  ASSERT(v1.size() == 1);

  /*
  std::string v2 = "2";
  auto obj2 = builder(std::move(v2));
  ASSERT(std::get<std::string>(obj2.m_value) == "2");
  ASSERT(v2.size() == 0);
  
  std::unique_ptr<int> ptr = std::make_unique<int>(5);
  auto obj3 = builder(std::move(ptr));
  ASSERT(ptr.get() == nullptr);
  ASSERT(*std::get<1>(obj3.m_value) == 5);
  */
}

}

void move_ex3()
{
  test_1();
}