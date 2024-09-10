#include <global.h>

class LargeObject
{
public:
  LargeObject() { ++s_constructed; }
  LargeObject(const LargeObject &) { ++s_constructed; }
  LargeObject &operator=(const LargeObject &) { ++s_copied; return *this; }

  static uint64_t s_constructed;
  static uint64_t s_copied;
  static uint64_t s_moved;
};

uint64_t LargeObject::s_constructed = 0;
uint64_t LargeObject::s_copied = 0;
uint64_t LargeObject::s_moved = 0;

void move_ex1();
void move_ex2();
void move_ex3();
void move_ex4();
void move_ex5();

int main()
{
  move_ex1();
  move_ex2();
  move_ex3();
  move_ex4();
  move_ex5();
}
