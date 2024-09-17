#include <global.h>
namespace
{
std::size_t allocationCount = 0;
std::size_t deallocationCount = 0;
}
//TODO: Uncomment the overloaded operators new and delete when working on this excercise.
//These overloads will increment the counters 'allocationCount' and 'deallocationCount' and are used in the excercise to track heap allocations and deallocations.
//It is a good idea to recomment these overloads when done with this excercise. The operator new will override the weakly defined new symbol of the stdlib. 
//This overload will force a replace of the symbol - executable wide.

/* 
void* operator new(std::size_t size) noexcept(false) {
    ++allocationCount;
    void* ptr = std::malloc(size);
    std::cout << "HEAP allocating " << size << " bytes. Total allocations: " << allocationCount << std::endl;
    return ptr;
}

void operator delete(void* ptr) noexcept {
    ++deallocationCount;
    std::free(ptr);
    std::cout << "HEAP deallocating " << std::endl;
}
*/

namespace
{
template <typename T>
class SimplePoolAllocator 
{
public:
    using value_type = T;
    using storage_type = std::unique_ptr<T>;
    const std::size_t MAX=10;
    SimplePoolAllocator()
    {
	//TODO: init 'm_pool'
    }
    //getlement from pool
    T* allocate(std::size_t n) noexcept
    {
	//TODO: return valid memory instead of a nullptr
    	return nullptr;
    }
    
    //add element back to pool
    void deallocate(T* p, std::size_t n) noexcept
    {
	//TODO: add element p back to the pool
    }

private:
    std::vector<storage_type> m_pool;
};
struct X
{
    std::array<uint64_t, 100> data;
};

//This function pushes 10 elements to a list it creates of type ListType.
//then it clears the list and pushes 10 elements to the list again.
template <typename ListType>
void doTest() 
{
    ListType myList;
    for (int i = 0; i<10; i++)
    {
        myList.push_back(typename ListType::value_type{});
    }
    myList.clear();
    for (int i = 0; i<10; i++)
    {
        myList.push_back(typename ListType::value_type{});
    }
}

//GOAL: The goal of this excercise is to demonstrate some methods to avoid unnecessary resource allocation penalties. 
//By default, using std::list will trigger 20 allocations, but this can be reduced to 11 with a pool allocator. 
//Further optimization can bring the number of allocations down to 10, as the maximum required allocations are known in advance.
void test_1()
{
    ASSERT(allocationCount == 0);
    doTest<std::list<int>>();
    //TODO: uncomment these asserts below when the overloaded operator new and delete are overloaded.
    //ASSERT(allocationCount == 20);
    //ASSERT(deallocationCount == 20);
	
    //TODO: Fix the SimplePoolAllocator implementation before uncommenting the assert below.
    //doTest<std::list<X, SimplePoolAllocator<X>>>();
    //ASSERT(allocationCount == 31); //11 = 1 + 10
    //ASSERT(deallocationCount == 31); //11 = 1 + 10
}
}
void cont_ex1()
{
  test_1();
}
