#include <global.h>


namespace
{

// This class should not be changed. It has all the required constructors to make the asserts succeed.
struct Object
{
  Object(const std::string &s) : m_value(s) {}
  Object(std::string &&s) : m_value(std::move(s)) {}
  Object(std::unique_ptr<int> &&i) : m_value(std::move(i)) {}
  
  std::variant<std::string, std::unique_ptr<int>> m_value;
};

//TODO: Modify this function, either be upgrading the argument to a universal reference or by providing
//a seperate move only overload.
Object builder(const std::string &v)
{
  return Object(v);
}

/* GOAL: Make the builder function work with types that support move semantics.
 * Right now, the function builder only works on l-values.
 * Either provide a move overload for the 'builder' function or use a universal reference.
 * The Object class should not be modified.
 */
void test_1()
{
  std::string v1 = "1";
  auto obj1 = builder(v1);
  ASSERT(std::get<std::string>(obj1.m_value) == "1");
  ASSERT(v1.size() == 1);

  //TODO: uncomment when the builder function has been reimplemented.
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
