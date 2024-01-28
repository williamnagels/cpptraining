#include <global.h>
namespace
{
std::size_t allocationCount = 0;
std::size_t deallocationCount = 0;
}
//uncomment these when working on this excercise to track heap allocations
//comment when done, dont want other tests to print something whenever
//they allocate, put asserts in comment again aswell when done.
//will overide weak symbol new with a global sombol here, this is binary wide
/*void* operator new(std::size_t size) noexcept(false) {
    ++allocationCount;
    void* ptr = std::malloc(size);
    std::cout << "HEAP allocating " << size << " bytes. Total allocations: " << allocationCount << std::endl;
    return ptr;
}

void operator delete(void* ptr) noexcept {
    ++deallocationCount;
    std::free(ptr);
    std::cout << "HEAP deallocating " << std::endl;
}*/

namespace{

template <typename T>
class SimplePoolAllocator {
public:
    using value_type = T;
    using storage_type = std::unique_ptr<T>;
    const std::size_t MAX=10;
    
    //init pool
    SimplePoolAllocator() {
    }
    //getlement from pool
    T* allocate(std::size_t n) noexcept {
	    return nullptr;
    }
    
    //add element back to pool
    void deallocate(T* p, std::size_t n) noexcept {
    }

private:
    std::vector<storage_type> m_pool;
};
struct X{
    std::array<uint64_t, 100> data;
};

template <typename ListType>
void doTest() {
    ListType myList;
    //pull all memory from pool to myList, size of pool = 10
    for (int i = 0; i<10; i++){
        myList.push_back(typename ListType::value_type{});
    }
    myList.clear(); //release memory back from myList to pool
    //pull all memory from pool to myList, size of pool = 10
    for (int i = 0; i<10; i++){
        myList.push_back(typename ListType::value_type{});
    }
}

//uncomment asserts below and make them succeed.
//20 allocations when working with default std::list template arguments
//should be 11 with pool allocator. Can be 10 if you want (since size -10- is known already)
void test_1() {
    ASSERT(allocationCount == 0);
    doTest<std::list<int>>();
    //ASSERT(allocationCount == 20);
    //ASSERT(deallocationCount == 20);
    //uncommenting the line below will crash until SimplePoolAllocator has been implemented
    //it returns nullptr right now, instead of actual usable memory when allocating.
    //doTest<std::list<X, SimplePoolAllocator<X>>>();
    //ASSERT(allocationCount == 31); //11 = 1 + 10
    //ASSERT(deallocationCount == 31); //11 = 1 + 10
}
}
void cont_ex1()
{
  test_1();
}