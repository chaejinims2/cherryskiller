#pragma once
#include "CalcGCD.h"

// GCD 테스트를 위한 헬퍼 함수들
inline bool isDivisor(int n, int d) {
    return d != 0 && n % d == 0;
}

inline bool areCoprime(int a, int b) {
    return gcd(a, b) == 1;
}