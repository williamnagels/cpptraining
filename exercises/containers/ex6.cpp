#include <global.h>

namespace
{
//GOAL: Copy the elements from container 'a' to container 'b' in such a way that there are no longer any consecutive equal integers in container 'b'.
//There are two 1s in container 'a' at index 2 and index 3. In container 'b' there should be a 1 at position 2 and a 2 at position 3.
void test_1()
{
    std::array<int, 10> a = {1, 2, 1, 1, 2, 4, 5, 6};
    std::array<int, 10> b;
    //TODO: add copy operation

    //TODO: uncomment the asserts when copy has been implemented.
    /* 
    ASSERT(b[0] == 1);
    ASSERT(b[1] == 2);
    ASSERT(b[2] == 1);
    ASSERT(b[3] == 2); // duplicate 1, has been filtered out
    ASSERT(b[4] == 4);
    ASSERT(b[5] == 5);
    ASSERT(b[6] == 6);
    ASSERT(b[7] == 0); // TODO: explain why a zero shows up in output 'b' while there is no zero in the input vector 'a'
    */
}

/*GOAL: There are cases where move semantics do not help at all, they may just overcomplicate the syntax and slow things down.
Imagine some scenario where container 'v' is no longer needed and can be destructed. The goal
is to move all std::string instances from 'v' to 'concat'. use std::algorithms.
The std::string instance 'concat' should contain the concatenated string, created by concatenating 
all strings from the std::vector instance 'v'

Note: Depending on your stdlib version and type the asserts may fail. Why is that?
*/
void test_2()
{
    std::vector<std::string> v{"some", "reallyactuallyreallyreallyreally", "long", "string"};
    std::string concat;
    //TODO: Add move operation: move all the elements from container 'v' to container 'c' while concatenating. 
    //Note: a special type of iterator has been provided by the standard to provide move support. The 'default'
    //iterators will copy construct/assign and are no good right now.

    //TODO: uncomment the asserts below
    //ASSERT(concat == "somereallyactuallyreallyreallyreallylongstring");

    // Note: the following assertions may fail depending on your compiler
    // and standard library implementation, because the state of v after
    // the move is implementation-defined
    /*ASSERT(v[0] == "some");
    ASSERT(v[1] == "");*/
    
    //TODO: Is moving the std::string instances into 'concat' more expensive than copying?
}
}

void cont_ex6()
{
  test_1();
  test_2();
}
