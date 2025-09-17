#include <gtest/gtest.h>
#include "Matrix.h"
#include "test_helpers.h"

TEST(MatrixMulVerification, IdentityMatrix) {
    Matrix I = {{1, 0}, {0, 1}};
    Matrix A = {{2, 3}, {4, 5}};

    Matrix C = multiply(A, I);
    EXPECT_TRUE(matricesEqual(A, C));
}

TEST(MatrixMulVerification, ThrowsOnInvalid) {
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6, 7}};
    EXPECT_THROW(multiply(A, B), std::invalid_argument);
}