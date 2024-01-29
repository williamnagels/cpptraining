#include <global.h>

namespace
{
struct Friend {
    std::string name;
    std::string dietaryPreference;
};
// Predicate for stable_partition
bool isVegetarian(const Friend& friendObj) {
    return true;
}

void test_1()
{
    // Split the list of friends in 2 parts, Vegetarian and non vegetarian. Do not create new lists.  
    // resuffle the list of friends so that all vegetarians are at the beginning of the list
    // dont change the order of friend objects (e.g: Alice should remain positioned before David)
    // There is one algorithm that can do this.
    std::vector<Friend> friends = {
        {"Alice", "Vegetarian"},
        {"Bob", "Pescatarian"},
        {"Charlie", "Carnivore"},
        {"David", "Vegetarian"},
        {"Eve", "Carnivore"},
        {"Frank", "Pescatarian"}
    };

    //iterator to the last vegetarian.
    auto it= std::begin(friends);

    //uncomment these asserts
    //ASSERT(std::distance(std::begin(friends), it) == 2);
    //ASSERT(std::distance(it, std::end(friends)) == 4);
}

}

void cont_ex8()
{
  test_1();
}