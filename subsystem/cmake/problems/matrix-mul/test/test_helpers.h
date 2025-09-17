#pragma once
#include "Matrix.h"

// 헬퍼 함수: 두 행렬이 같은지 비교
inline bool matricesEqual(const Matrix& A, const Matrix& B) {
    if (A.size() != B.size()) return false;
    for (size_t i = 0; i < A.size(); i++) {
        if (A[i].size() != B[i].size()) return false;
        for (size_t j = 0; j < A[i].size(); j++) {
            if (A[i][j] != B[i][j]) return false;
        }
    }
    return true;
}
