#include <global.h>

namespace
{
struct Friend 
{
    std::string name;
    std::string dietaryPreference;
};

// Predicate used to split the lists
bool isVegetarian(const Friend& friendObj)
{
    return true; //TODO: Fix predicate
}

/*
GOAL:
The goal of this excersise is to gain some more familiarity with algorithms that modify the content of containers

Reorder the existing list 'friends' into 2 parts. Vegetarians and non vegetarians. Do not create new lists,
re-order the existing friends list in place.
Reorder the list of friends so that all vegetarians are at the beginning of the list.
Do not change the order of friend instances (e.g.: after reordering Alice is still before David in the list)

There is one algorithm that can do this.
*/
void test_1()
{
    std::vector<Friend> friends = 
    {
        {"Alice", "Vegetarian"},
        {"Bob", "Pescatarian"},
        {"Charlie", "Carnivore"},
        {"David", "Vegetarian"},
        {"Eve", "Carnivore"},
        {"Frank", "Pescatarian"}
    };

    //TODO:Fix this - Iterator to the last vegetarian, use an algorithm with
    //the predicate 'isVegetarian'.
    auto it= std::begin(friends);
    //TODO: Uncomment these asserts
    //ASSERT(std::distance(std::begin(friends), it) == 2);
    //ASSERT(std::distance(it, std::end(friends)) == 4);
    //ASSERT(it->name == "Bob"); 
}

}

void cont_ex8()
{
  test_1();
}
