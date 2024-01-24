#include <iostream>
#include <stdint.h>
#include <functional>
#include <utility>
#include <memory>
#include <vector>
#include <map>
#include <deque>
#include <variant>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <variant>
#include <chrono>

#define STR(x) #x
#define ASSERT(x) if (not (x)) { std::cerr << "Assertion failed: (" << STR(x) << "), function " << __PRETTY_FUNCTION__ << ", file " << __FILE__ << ", line " << __LINE__ << ".\n"; exit(1); }
