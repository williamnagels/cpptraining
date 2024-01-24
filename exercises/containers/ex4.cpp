#include <global.h>

namespace
{
//Copy the elements from the range a to std::out in such a way that there are no consecutive equal elements. 
//special purpose std::ostream_iterators exist for the purpose of pushing elements to streaming outputs
//expected output: 1, 2, 1, 2, 4, 5, 6, 0, 
void test_1()
{
    std::array<int, 10> a = {1, 2, 1, 1, 2, 4, 5, 6};
    std::ostream_iterator<int> out_it (std::cout,", ");
}
//The container v is spent and we dont need it anymore. We want a concatenated string of all parts in concat.
//Move the resources of v into concat
//Is this useful?
//Depending on your compiler 
    //ASSERT(v[0] == "some");
    //ASSERT(v[1] == "");
//may fail and you need to change these assets, why is the result of these asserts implementation defined?
void test_2()
{
    std::vector<std::string> v{"some", "reallyactuallyreallyreallyreally", "long", "string"};
    std::string concat;
 
    //ASSERT(concat == "somereallyactuallyreallyreallyreallylongstring");
    //ASSERT(v[0] == "some");
    //ASSERT(v[1] == "");
}
}

void cont_ex4()
{
  test_1();
  test_2();

}