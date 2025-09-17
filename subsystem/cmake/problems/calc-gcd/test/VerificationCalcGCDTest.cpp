#include <gtest/gtest.h>
#include <climits>
#include "CalcGCD.h"
#include "test_helpers.h"

TEST(VerificationCalcGCD, AlgorithmConsistency) {
    // 두 알고리즘이 같은 결과를 내는지 확인
    EXPECT_EQ(gcd(48, 18), gcdEuclidean(48, 18));
    EXPECT_EQ(gcd(1001, 91), gcdEuclidean(1001, 91));
    EXPECT_EQ(gcd(123456, 789), gcdEuclidean(123456, 789));
    EXPECT_EQ(gcd(1, 1), gcdEuclidean(1, 1));
}

TEST(VerificationCalcGCD, MathematicalProperties) {
    // GCD의 수학적 성질 검증
    int a = 24, b = 36;
    int g = gcd(a, b);
    
    // GCD는 두 수의 약수여야 함
    EXPECT_EQ(a % g, 0);
    EXPECT_EQ(b % g, 0);
    
    // GCD는 두 수를 나눈 결과는 서로소여야 함
    EXPECT_EQ(gcd(a / g, b / g), 1);
}

TEST(VerificationCalcGCD, EdgeCases) {
    // 극단적인 경우들
    EXPECT_EQ(gcd(1, 1000000), 1);
    EXPECT_EQ(gcd(1000000, 1), 1);
    EXPECT_EQ(gcd(INT_MAX, 1), 1);
    EXPECT_EQ(gcd(1, INT_MAX), 1);
}

TEST(VerificationCalcGCD, PrimeNumbers) {
    // 소수들의 GCD는 1이어야 함
    EXPECT_EQ(gcd(17, 19), 1);
    EXPECT_EQ(gcd(23, 29), 1);
    EXPECT_EQ(gcd(31, 37), 1);
    EXPECT_EQ(gcd(41, 43), 1);
}

TEST(VerificationCalcGCD, PerformanceTest) {
    // 큰 수들에 대한 성능 테스트
    int result1 = gcd(123456789, 987654321);
    int result2 = gcdEuclidean(123456789, 987654321);
    EXPECT_EQ(result1, result2);
    EXPECT_GT(result1, 0);
}
