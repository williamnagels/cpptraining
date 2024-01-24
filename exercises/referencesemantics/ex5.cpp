#include <global.h>


namespace
{

template <typename T>
class SafePtr
{
};

}

void move_ex5()
{
  /*
   * Let's put it all together.
   * We are going to make a class that mimics the unique_ptr class in the STL
   *
   * Add the following to the "SafePtr" class:
   *   - A public constructor that accepts a pointer to the class we are wrapping
   *   - A private member pointer to the object that we received in the constructor
   *   - A default constructor that initializes the member with a nullptr
   *   - A destructor that deletes the object
   *   - A dereference operator to get to the object stored
   *   - A get function that returns the pointer value stored
   *   - A boolean test operator that checks if the member variable is set or not
   */

  /*
   * If you did your job, the following code should work
   */
  // SafePtr<int> p1{new int(1)};
  // ASSERT(*p1 == 1);
  // SafePtr<int> p2{new int(2)};
  // ASSERT(*p2 == 2);
  // SafePtr<int> p3{};
  // ASSERT(p3.get() == nullptr);

  /*
   * Add a move constructor so that it can handle the following code
   */
  // SafePtr<int> p4 = SafePtr<int>(new int(4));
  // ASSERT(*p4 == 4);
  // std::vector<SafePtr<int>> v;
  // v.push_back(SafePtr<int>(new int(1)));
  // ASSERT(*v[0] == 1);
  // SafePtr<int> p5{new int(5)};
  // SafePtr<int> p6 = std::move(p5);
  // ASSERT(*p6 == 5);
  // ASSERT(p5.get() == nullptr);

  /*
   * Add a move assignment operator and uncomment the code below
   */
  // SafePtr<int> p7 = SafePtr<int>(new int(7));
  // SafePtr<int> p8 = SafePtr<int>(new int(8));
  // p7 = std::move(p8);
  // ASSERT(*p7 == 8);
  // ASSERT(p8.get() == nullptr);

  // Bonus points if you provide an option to provide a deallocator that 
  // does not increase the size of the SafePtr type.
}