#include <gtest/gtest.h>
#include "Matrix.h"
#include "test_helpers.h"

TEST(MatrixMulVerification, ZeroMatrix) {
    Matrix Z = {{0, 0}, {0, 0}};
    Matrix A = {{2, 3}, {4, 5}};

    Matrix C = multiply(A, Z);
    Matrix expected = {{0, 0}, {0, 0}};
    EXPECT_TRUE(matricesEqual(C, expected));
}

TEST(MatrixMulVerification, AssociativeProperty) {
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};
    Matrix C = {{9, 10}, {11, 12}};

    Matrix AB = multiply(A, B);
    Matrix ABC = multiply(AB, C);
    
    Matrix BC = multiply(B, C);
    Matrix ABC2 = multiply(A, BC);
    
    EXPECT_TRUE(matricesEqual(ABC, ABC2));
}

TEST(MatrixMulVerification, LargeMatrix) {
    Matrix A = {{1, 2, 3}, {4, 5, 6}};
    Matrix B = {{7, 8}, {9, 10}, {11, 12}};
    
    Matrix C = multiply(A, B);
    Matrix expected = {{58, 64}, {139, 154}};
    EXPECT_TRUE(matricesEqual(C, expected));
}