#include "Matrix.h"
#include <stdexcept>

Matrix multiply(const Matrix& A, const Matrix& B) {
    if (A.empty() || B.empty())
        throw std::invalid_argument("Empty matrix not allowed");

    size_t n = A.size();
    size_t m = A[0].size();
    size_t p = B[0].size();

    if (B.size() != m) {
        throw std::invalid_argument("Invalid dimensions for multiplication");
    }

    Matrix C(n, std::vector<int>(p, 0));

    for (size_t i = 0; i < n; i++) {
        for (size_t k = 0; k < m; k++) {
            for (size_t j = 0; j < p; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}