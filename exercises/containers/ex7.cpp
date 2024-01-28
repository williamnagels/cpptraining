#include <global.h>

namespace
{
/*
template <typename T, std::size_t SIZE>
class Array
{
public:

    struct Iterator 
    {
        using iterator_category = std::bidirectional_iterator_tag ;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;
        using reference         = T&;

        Iterator() {}

        reference operator*() const { }
        pointer operator->() {}
        Iterator& operator++() { }  
        Iterator operator++(int) {}
        friend bool operator== (const Iterator& a, const Iterator& b) { };
        friend bool operator!= (const Iterator& a, const Iterator& b) { };  

    private:
    };

    Iterator begin() { }
    Iterator end()   { }
};*/
//It is possible to create custom iterators for a type.
//Lets create our own std::array. and put the first 100 fibonacci nrs as values by using std::generate
//and our own iterator.
//a blueprint for a custom array type with own iterator is provided above. 
//Forget about the leading zero of that series. or dont. but then you have to change the assert to take that into account
void test_1()
{
//    Array<int, 100> test;
//   ASSERT(test[0] == 1);
//   ASSERT(test[4] == 8);
}
}

void cont_ex7()
{
  test_1();
}