#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>


#include <string>

#include "../include/pecc.h"


TEST_CASE("prrrecc", "pecc33")
{
    std::string teststr("");
    peccer(teststr);

    REQUIRE(teststr == "you got pecced\n");
    
}
