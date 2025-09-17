#include "gtest/gtest.h"
#include "../src/Calculator.h"

class CalculatorTest : public ::testing::Test {
protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

    Calculator calculator;
};

TEST_F(CalculatorTest, Adding) {
    EXPECT_EQ(2, calculator.Add(1, 1));
}

TEST_F(CalculatorTest, Subtraction) {
    EXPECT_EQ(5, calculator.Subtract(10, 5));
}

TEST_F(CalculatorTest, Multiplication) {
    EXPECT_EQ(2, calculator.Multiply(1, 2));
}

TEST_F(CalculatorTest, Division) {
    EXPECT_EQ(2, calculator.Divide(2, 1));
}