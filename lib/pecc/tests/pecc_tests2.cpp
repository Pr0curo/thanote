#include <catch2/catch.hpp>


#include <string>

#include "../include/pecc.h"


TEST_CASE("peccer_tests", "test_001")
{
    std::string teststr("");
    peccer(teststr);
    REQUIRE(teststr == "you got pecced\n");

    std::string teststr2("222_");
    peccer(teststr2);
    REQUIRE(teststr2 == "222_you got pecced\n");
    std::cout << teststr2;
}
