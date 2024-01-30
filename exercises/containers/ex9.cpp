#include <global.h>

namespace
{
void test_1()
{
    // Creating a vector of words
    std::vector<std::string> words = {"apple", "bananaman", "kiwi", "grape"};

    auto longest = std::begin(words); //find the longest word in the set of words

    //uncomment the assert
    //ASSERT(*longest == "bananaman");

    // print the full vector to std::cout using std::ostream_iterator
}
}

void cont_ex9()
{
  test_1();
}