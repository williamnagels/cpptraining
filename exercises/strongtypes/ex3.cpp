#include <global.h>
namespace
{
// Forward declaration for Distance
template <typename Unit>
struct Distance;

using Kilometer = Distance<std::kilo>;
using Centimeter = Distance<std::centi>;
using Micrometer = Distance<std::micro>;
using Meter = Distance<std::ratio<1, 1>>;

template <typename FromUnit, typename ToUnit>
Distance<ToUnit> convert(const Distance<FromUnit>& distance) {
    return Distance<ToUnit>{1};
}
template <typename Unit>
struct Distance {
    using Ratio = Unit;
    double value;

    // Constructor to initialize the distance value
    explicit Distance(double value) : value(value) {}

    // Add templated constructor here that uses the convert function
    //template <typename OtherUnit>
    //Distance(const Distance<OtherUnit>& other)

    // Overload the + operator to add distances of different units
    template <typename OtherUnit>
    Distance<Ratio> operator+(const Distance<OtherUnit>& other) const {
        return Distance<Ratio>(value + convert<OtherUnit, Distance<Ratio>>(other).value);
    }
};
template <typename Ratio>
std::ostream& operator<<(std::ostream& os, Distance<Ratio> const& distance) {
    //convert to meter and print value
    return os;
}

void test_1()
{
    Kilometer kmDistance(2.5);
    Centimeter cmDistance(120);
    /*Micrometer microDistance = kmDistance;
    Micrometer microDistance2 = cmDistance + microDistance;

    std::cout << "Distance kilometers: " << kmDistance << std::endl;
    std::cout << "Distance cmDistance: " << cmDistance << std::endl;
    std::cout << "Distance µDistance: " << microDistance << std::endl;

    std::stringstream ss;
    ss << microDistance;*/
    //ASSERT(ss.str() == "2.5e+09 micron");
    //ASSERT(microDistance2.value == 2.5012e+09);
}
}
void type_safe_ex3()
{
  test_1();
}