#include <global.h>

namespace
{

struct Vehicle
{
// TODO: Add l-value and r-value constructors.
// TODO: Add a templated constructor for specific use cases.
// TODO: Add a destructor that cleans up the vtable member by destroying the concrete instance.
};

//The classes Car and Bus should not be changed for these excercises. Only vehicle has to be changed.
struct Car
{
  std::string id() { return m_id; }
  std::string m_id;
  int m_int = 1;
};

struct Bus
{
  std::string id() { return m_id; }
  std::string m_id;
  int m_int = 2;
};

/**
 * GOAL: Experiment with external inheritance by extending the Vehicle class.
 * Compare the effectiveness of value semantics with internal versus external inheritance to determine which works most intuitivly.
 */
void test_1()
{
// TODO: Uncomment the asserts below and fix the TODOs in the Vehicle class.
// The copy constructor is not needed for this exercise yet.

/*
  std::vector<Vehicle> vs;
  vs.emplace_back(Car{"car_1"});
  vs.emplace_back(Car{"car_2"});
  vs.emplace_back(Bus{"bus_1"});
  vs.emplace_back(Bus{"bus_2"});
  
  ASSERT(vs[0].id() == "car_1");
  ASSERT(vs[1].id() == "car_2");
  ASSERT(vs[2].id() == "bus_1");
  ASSERT(vs[3].id() == "bus_2");
*/
}
/**
 * GOAL: Continuation of test_1. Split test_1 and test_2 to minimize the changes needed to the Vehicle class in a single test.
 */
void test_2()
{
  // TODO: Uncomment the asserts below. The copy constructor will be required 
  // for this exercise.
/*
  std::vector<Vehicle> v_old;
  v_old.emplace_back(Car{"car_1"});
  v_old.emplace_back(Car{"car_2"});
  v_old.emplace_back(Bus{"bus_1"});
  v_old.emplace_back(Bus{"bus_2"});
  
  auto v_new = v_old;
  ASSERT(v_old[0].id() == "car_1");
  ASSERT(v_new[1].id() == "car_2");
  ASSERT(v_old[2].id() == "bus_1");
  ASSERT(v_new[3].id() == "bus_2");
*/
}

/**
 * GOAL: Provide direct access to member variables rather than through accessor functions.
 * Extend the vtable implementation to expose direct access to the internal m_id member.
 */
void test_3()
{
  // TODO: Add a method to the vtable that returns an l-value reference to an int.
  // uncomment the asserts.
 /*
  std::vector<Vehicle> v;
  v.emplace_back(Car{"car_1"});
  v.emplace_back(Bus{"bus_1"});
  
  ASSERT(v[0].id() == "car_1");
  ASSERT(v[0].m_int == 1);
  ASSERT(v[1].id() == "bus_1");
  ASSERT(v[1].m_int == 2);
 */
}


}
 
void values_ex2()
{
  test_1();
  test_2();
  test_3();
}
