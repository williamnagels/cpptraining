#include <global.h>

namespace
{

// for the exercises in this file, you can use cppreference as a guide
// https://en.cppreference.com/w/cpp/chrono

// create a new type that represents a duration of 1/60000th of a second
// use std::chrono as it already has all the features we need
// using Duration60kHz = ...;


// now change the following code to make it type safe
void test_1()
{
  int64_t time2sec = 2 * 60000;
  int64_t time100ms = 100 * 60;
  int count = 10;
  int64_t total = (time2sec + time100ms) * count;
  ASSERT(total == 1260000);
}

// create a time point that represents the UTC time in 1/60000th of a second
// using Time60kHzUtc = ...;

// create a function 'now' that returns the current UTC time in our new time point
// auto now() { ... }

// use this clock to change and modify the the following code
// you can add a special ostream overload for our custom type if you want
void test_2()
{
  auto start = std::chrono::system_clock::now();
  // do some work
  std::vector<int> v;
  for (int i = 0; i < 10000; ++i) v.push_back(i);
  auto total = std::accumulate(v.begin(), v.end(), 0u);
  (void)total;
  // record end time
  auto end = std::chrono::system_clock::now();
  auto diff = end - start;
  std::cout << "test_2 diff: " << diff.count() << "\n";
}


// What does the following function print?
// Is this what we expect?
// Modify the following function to use std::chrono types
// What did the compiler do to help you?
void test_3()
{
  // these are all the lap times in miliseconds
  std::vector<uint64_t> lap_times{400, 356, 402, 397, 402, 386};
  uint64_t total_sec = 0;
  for (auto i : lap_times)
    total_sec += i / 1000;
  std::cout << "test_3: The total time is " << total_sec << " seconds\n";
}

}
 
void type_safe_ex2()
{
  std::cout << "type_safe_ex1\n";
  test_1();
  test_2();
  test_3();
}