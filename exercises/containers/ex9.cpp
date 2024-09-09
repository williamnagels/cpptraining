#include <global.h>

namespace
{
void test_1()
{
    std::vector<std::string> words = {"apple", "bananaman", "kiwi", "grape"};
    //TODO: Update the algorithm so that the iterator 'it' points to the longest word (bananaman)
    auto it = std::begin(words);
    
    //TODO: Uncomment the assert
    //ASSERT(*it == "bananaman");
    
    //TODO: Write the full vector to the standard output using std::ostream_iterator
}
}

void cont_ex9()
{
  test_1();
}
