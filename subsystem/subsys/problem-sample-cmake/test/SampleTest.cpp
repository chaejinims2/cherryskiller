#include "gtest/gtest.h"
#include "../src/Sample.h"

class SampleTest : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

    Sample sample;
};

TEST_F(SampleTest, Adding) {
    EXPECT_EQ(2, sample.Add(1, 1));
}

TEST_F(SampleTest, Subtraction) {
    EXPECT_EQ(5, sample.Subtract(10, 5));
}

TEST_F(SampleTest, Multiplication) {
    EXPECT_EQ(2, sample.Multiply(1, 2));
}

TEST_F(SampleTest, Division) {
    EXPECT_EQ(2, sample.Divide(2, 1));
}