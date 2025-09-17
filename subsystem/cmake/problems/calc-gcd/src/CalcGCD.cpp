#include "CalcGCD.h"
#include <algorithm>
#include <stdexcept>

// 최대공약수 계산 (기본 구현)
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    if (a == 0 && b == 0) {
        throw std::invalid_argument("GCD of (0, 0) is undefined");
    }
    
    if (a == 0) return b;
    if (b == 0) return a;
    
    // 간단한 방법: 1부터 min(a,b)까지 나누어보기
    int result = 1;
    for (int i = 1; i <= std::min(a, b); ++i) {
        if (a % i == 0 && b % i == 0) {
            result = i;
        }
    }
    return result;
}

// 유클리드 알고리즘을 사용한 최대공약수 계산
int gcdEuclidean(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    if (a == 0 && b == 0) {
        throw std::invalid_argument("GCD of (0, 0) is undefined");
    }
    
    if (a == 0) return b;
    if (b == 0) return a;
    
    // 유클리드 알고리즘
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
