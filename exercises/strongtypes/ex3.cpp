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

// Converts a distance with precision 'FromUnit' to a distance with precision 'ToUnit'
template <typename FromUnit, typename ToUnit>
Distance<ToUnit> convert(const Distance<FromUnit>& distance)
{
    //TODO: implement this function
    return Distance<ToUnit>{1};
}
template <typename Unit>
struct Distance
{
    using Ratio = Unit;
    double value;

    // Create a distance object with precision 'Unit' using some unsafe value.
    explicit Distance(double value) : value(value) {}

    // TODO: Add a templated constructor to create an object of type Distance with precision 'Unit' from a 
    // distance instance with precision 'OtherUnit'.
    //template <typename OtherUnit>
    //Distance(const Distance<OtherUnit>& other)

    // Implements the plus-operator 'operator+' for instances of type Distance with any precision. No changes needed here.
    // TODO : is this safe? What can go wrong ? can you detect the issue and throw a compiler error when the issue occurs?
    template <typename OtherUnit>
    Distance<Ratio> operator+(const Distance<OtherUnit>& other) const
    {
        return Distance<Ratio>(value + convert<OtherUnit, Distance<Ratio>>(other).value);
    }
};

// This function takes a Distance type with any precision. It will 
// convert the precision to meters and then stream the resulting value to output stream os.
template <typename Ratio>
std::ostream& operator<<(std::ostream& os, Distance<Ratio> const& distance)
{
    //TODO: convert distance to a distance in meter and write to os.
    return os;
}

//TODO: Add a specific streaming operator 'operator<<' overload for micron. 
//Microns should not be printed in meter precision but rather in full precision without conversion. 
//There is an assert in test_1 which tests the output of this overload so you have to 
//format the output to match the assert.

/*
GOAL: Use the chrono std::rate library in a custom type to express units of distance
instead of time.
*/
void test_1()
{
    Kilometer kmDistance(2.5);
    Centimeter cmDistance(120);
    //TODO: uncomment the asserts when the other TODOs have been fixed.    
    /*
    Micrometer microDistance = kmDistance;
    Micrometer microDistance2 = cmDistance + microDistance;

    std::cout << "Distance kilometers: " << kmDistance << std::endl;
    std::cout << "Distance cmDistance: " << cmDistance << std::endl;
    std::cout << "Distance µDistance: " << microDistance << std::endl;

    std::stringstream ss;
    ss << microDistance;
    ASSERT(ss.str() == "2.5e+09 micron");
    ASSERT(microDistance2.value == 2.5012e+09);
    */
}
}
void type_safe_ex3()
{
  test_1();
}
