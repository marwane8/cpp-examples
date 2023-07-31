#include<gtest/gtest.h>
#include "adder.h"

TEST(Adding,Adding){

    int x = 3;
    int ans = mathapp::addByTwo(x);
    ASSERT_EQ(ans,5);
}
