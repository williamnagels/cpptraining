#include <global.h>
namespace
{
/*
TODO: Uncomment the class 'Array' below, implement the iterator methods of the nested Iterator type 
in a way that the Iterator class behaves like an actual random access iterator.
Add some kind of member variable to the Iterator class to be able to store a reference to an instance of 
type T stored in the Array<T, SIZE> . Type T is exposed by dereferencing the Iterator type.
*/

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
        Iterator& operator++() { }  //prefix operator overload
        Iterator operator++(int) {} //postfix operator overload
        friend bool operator== (const Iterator& a, const Iterator& b) { };
        friend bool operator!= (const Iterator& a, const Iterator& b) { };  

    private:
    };

    Iterator begin() { }
    Iterator end()   { }
};*/

/*
GOAL:
The goal of this excercise is to implement std::array and show how easy it is to expose access to internal data
with a custom iterator that can be used by algorithms from the STL.
*/
void test_1()
{
    //TODO: uncomment the instantiation of the object of type 'Array' when the class 'Array' has been implemented.
    // Array<int, 100> test;
    
    //TODO: Add code to assign the values of the first 100 fibonnaci numbers to the array
    //TIP: std::generate may be useful. NOTE: the asserts do not expect the leading zeroes in the fibonnaci series.
    
    //TODO: uncomment the asserts below, these assserts assume fibonnaci starts with 1, 
    //if the fibonacci numbers you generated include leading zero's change the assert
    // ASSERT(test[0] == 1);
    // ASSERT(test[4] == 8);
}
}

void cont_ex7()
{
  test_1();
}
