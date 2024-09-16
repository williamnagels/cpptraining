#include <global.h>
namespace
{
//align memory on cache line to avoid false sharing
int t1_value;
int t2_value;

void updateArray1()
{
    for (int i = 0; i < 1000000000; ++i) {
        t1_value += i;
    }
}

void updateArray2()
{
    for (int i = 0; i < 1000000000; ++i) {
        t2_value += i;
    }
}

void test_1()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::thread thread1(updateArray1);
    std::thread thread2(updateArray2);
    thread1.join();
    thread2.join();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    //compare times with and without false sharing
    std::cout << "duration: " << duration << " microseconds\n";
    std::cout << &t1_value<<std::endl;
    std::cout << &t2_value<<std::endl;
}
}
void cont_ex2()
{
  test_1();
}
