#include <global.h>

namespace
{
/*
GOAL:
The goal of this excercise is to show that you can create iterators that assign to something non iterable.
*/
void test_1()
{
    std::vector<std::string> words = {"apple", "bananaman", "kiwi", "grape"};
    //TODO: Update the algorithm so that the iterator 'it' points to the longest word (bananaman)
    auto it = std::begin(words);
    
    //TODO: Uncomment the assert
    //ASSERT(*it == "bananaman");
    
    //TODO: Copy the contents of it to the standard output using std::ostream_iterator
    //expected result is to see 'bananaman' printed on the stdout.
    //std::copy(it, ...)
}
}

void cont_ex9()
{
  test_1();
}
