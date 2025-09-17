#pragma once
#include <vector>

using Matrix = std::vector<std::vector<int>>;

// 행렬 곱셈 함수 (A x B = C)
Matrix multiply(const Matrix& A, const Matrix& B);