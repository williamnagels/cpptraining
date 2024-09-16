#include <global.h>

namespace
{
// GOAL: Get familiar with the std::chrono libraries of the standard library.
// There is plenty of documentation on https://en.cppreference.com/w/cpp/chrono
// which you have to use to get through this and following excercises.
void test_1()
{
  
  //TODO: While the code below works. It is not typesafe. there is no way the ensure that everyone is
  //using the precision to store in the integers. replace the int64_t with a new type Duration60kHz.
  //Duration60kHz represents a duration of 1/60000 of a second.
  //using Duration60kHz = std::chrono::duration<...>;
  int64_t time2sec = 2 * 60000;
  int64_t time100ms = 100 * 60;
  int count = 10;
  int64_t total = (time2sec + time100ms) * count;
  ASSERT(total == 1260000);
}

// GOAL: Gain familiarity with the std::chrono library in the standard library.
// std::chrono also supports time points, which represent specific moments in time, unlike durations.
// An example of a time point could be a timestamp when a log entry was added to a log file.
// The task is to update the function below to measure the execution time of std::accumulate 
// in 60kHz ticks (1/60000th of a second).
// TODO: Define a time point type, Time60kHzUtc, representing UTC time in 1/60000th of a second.
void test_2()
{
  // TODO: Implement a function 'now' that returns the current UTC time as a 60kHz time point.
  // The standard library's now() function does not provide 60kHz precision, so a custom now() implementation is needed.
  auto start = std::chrono::system_clock::now();
  
  // Do some works. ignore this. trying to burn some CPU cycles. No changes needed here.
  std::vector<int> v;
  for (int i = 0; i < 10000; ++i) v.push_back(i);
  auto total = std::accumulate(v.begin(), v.end(), 0u);
  
  // TODO: update this system_clock::now() call aswell.
  auto end = std::chrono::system_clock::now();
  auto diff = end - start;
  std::cout << "test_2 diff: " << diff.count() << " total=" << total <<std::endl;
}

// GOAL: std::chrono can prevent common math mistakes. This excercise shows how
// with strong type (like std::chrono) the compiler is able to warn us of bad math.
void test_3()
{
  // TODO: change the type of the contained elements in container lap_times.
  // lap_times contains durations in milliseconds. There is a type in the standard that expresses exactly that.
  std::vector<uint64_t> lap_times{400, 356, 402, 397, 402, 386};
  // TODO: change the type of total_sec to a duration in seconds
  uint64_t total_sec = 0;
  for (auto i : lap_times)
    //TODO: fix the math
    total_sec += i / 1000;
  //TODO: When the TODOs above are fixed, the print should be correct.
  std::cout << "test_3: The total time is " << total_sec << " seconds\n";
  //TODO: did you encounter any compiler warning that helped in detection loss of precision ?
}

}
 
void type_safe_ex2()
{
  test_1();
  test_2();
  test_3();
}
