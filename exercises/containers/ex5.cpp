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
        using iterator_category = 
        using difference_type   = 
        using value_type        = 
        using pointer           = 
        using reference         = 

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
//Lets create our own std::array. and put the first 100 fibonacci nrs as values.
//a blueprint for a custom array type with own iterator is available. 
//forget about the leading zero of that series. or dont. but then you have to change the assert
void test_1()
{
//    Array<int, 100> test;
//   ASSERT(test[0] == 1);
//   ASSERT(test[4] == 8);
}
}

void cont_ex5()
{
  test_1();
}