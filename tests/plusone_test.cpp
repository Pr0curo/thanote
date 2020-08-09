#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

unsigned int plusone(unsigned int a);

TEST_CASE("pl", "plusone")
{
    REQUIRE(plusone(3) == 4); 
}