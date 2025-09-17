#include "gtest/gtest.h"
#include "../src/Sample.h"

class VerificationSampleTest : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

    Sample sample;
};

TEST_F(VerificationSampleTest, Adding) {
    EXPECT_EQ(0, sample.Add(-1, 1));
    EXPECT_EQ(-2, sample.Add(-1, -1));
}

TEST_F(VerificationSampleTest, Subtraction) {
    EXPECT_EQ(5, sample.Subtract(10, 5));
}

TEST_F(VerificationSampleTest, Multiplication) {
    EXPECT_EQ(1, sample.Multiply(1, 1));
    EXPECT_EQ(0, sample.Multiply(1, 0));
}

TEST_F(VerificationSampleTest, Division) {
    EXPECT_EQ(2, sample.Divide(2, 1));
}

TEST_F(VerificationSampleTest, DivisionFloat) {
    EXPECT_EQ(0.5, sample.Divide(1, 2));
}

TEST_F(VerificationSampleTest, DivisionByZero) {
    EXPECT_EQ(std::numeric_limits<double>::infinity(), sample.Divide(1, 0));
}