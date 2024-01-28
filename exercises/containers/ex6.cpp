#include <global.h>

namespace
{
//Copy the elements from the range a to std::out in such a way that there are no consecutive identical elements are printed
//special purpose std::ostream_iterators exist for the purpose of pushing elements to streaming outputs
//expected output: 1, 2, 1, 2, 4, 5, 6, 0, Notice the double 1, wedged between both 2s was not printed.
void test_1()
{
    std::array<int, 10> a = {1, 2, 1, 1, 2, 4, 5, 6};
    std::ostream_iterator<int> out_it (std::cout,", ");
}
//The container v is no longer needed. Concatenate all strings of v into destination concat by moving them into the destination string.
//Is this useful? Did move semantics help us reuse any memory here?
//Depending on your stdlib implementation 
    //ASSERT(v[0] == "some");
    //ASSERT(v[1] == "");
//may fail and you need to change these asserts, why is the result of these asserts stdlib implementation defined?
void test_2()
{
    std::vector<std::string> v{"some", "reallyactuallyreallyreallyreally", "long", "string"};
    std::string concat;
 
    //ASSERT(concat == "somereallyactuallyreallyreallyreallylongstring");
    //ASSERT(v[0] == "some");
    //ASSERT(v[1] == "");
}
}

void cont_ex6()
{
  test_1();
  test_2();
}