#include <gtest/gtest.h>
#include "CalcGCD.h"
#include "test_helpers.h"

TEST(CalcGCDTest, BasicCases) {
    EXPECT_EQ(gcd(12, 8), 4);
    EXPECT_EQ(gcd(15, 25), 5);
    EXPECT_EQ(gcd(17, 13), 1);  // 서로소
    EXPECT_EQ(gcd(100, 50), 50);
}

TEST(CalcGCDTest, ZeroCases) {
    EXPECT_EQ(gcd(0, 5), 5);
    EXPECT_EQ(gcd(7, 0), 7);
    EXPECT_THROW(gcd(0, 0), std::invalid_argument);
}

TEST(CalcGCDTest, NegativeNumbers) {
    EXPECT_EQ(gcd(-12, 8), 4);
    EXPECT_EQ(gcd(15, -25), 5);
    EXPECT_EQ(gcd(-17, -13), 1);
}

TEST(CalcGCDTest, SameNumbers) {
    EXPECT_EQ(gcd(7, 7), 7);
    EXPECT_EQ(gcd(1, 1), 1);
    EXPECT_EQ(gcd(0, 0), 0);  // 이 경우는 예외가 발생해야 함
}

TEST(CalcGCDTest, LargeNumbers) {
    EXPECT_EQ(gcd(1000, 500), 500);
    EXPECT_EQ(gcd(12345, 67890), 15);
}
