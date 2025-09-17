#include "gtest/gtest.h"
#include "../src/Calculator.h"

class VerificationCalculatorTest : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

    Calculator calculator;
};

TEST_F(VerificationCalculatorTest, Adding) {
    EXPECT_EQ(0, calculator.Add(-1, 1));
    EXPECT_EQ(-2, calculator.Add(-1, -1));
}

TEST_F(VerificationCalculatorTest, Subtraction) {
    EXPECT_EQ(5, calculator.Subtract(10, 5));
}

TEST_F(VerificationCalculatorTest, Multiplication) {
    EXPECT_EQ(1, calculator.Multiply(1, 1));
    EXPECT_EQ(0, calculator.Multiply(1, 0));
}

TEST_F(VerificationCalculatorTest, Division) {
    EXPECT_EQ(2, calculator.Divide(2, 1));
}

TEST_F(VerificationCalculatorTest, DivisionFloat) {
    EXPECT_EQ(0.5, calculator.Divide(1, 2));
}

TEST_F(VerificationCalculatorTest, DivisionByZero) {
    EXPECT_EQ(std::numeric_limits<double>::infinity(), calculator.Divide(1, 0));
}