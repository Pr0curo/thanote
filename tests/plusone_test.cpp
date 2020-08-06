#include <gtest/gtest.h>

unsigned int plusone(unsigned int a);

TEST(pl, plusone)
{
    EXPECT_EQ(plusone(3), 4);
}