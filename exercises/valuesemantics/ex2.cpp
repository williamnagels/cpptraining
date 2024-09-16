#include <global.h>

namespace
{

struct Vehicle
{
};

struct Car
{
  std::string m_id;
};

struct Bus
{
  std::string m_id;
};

/**
 * Uncomment the following code and make it work
 */
void test_1()
{
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
 * Uncomment the following code and make it work
 */
void test_2()
{
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
 * Can you also provide access to member variables iso functions?
 * Add a int member to Car and Bus and provide access to it via Vehicle
 * Uncomment the following code and make it work
 */
void test_3()
{
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
 
void values_ex4()
{
  test_1();
  test_2();
  test_3();
}
