# Calculator Problem

C++와 CMake를 사용하여 기본적인 계산기 클래스를 구현하는 문제입니다.

## 문제 설명

간단한 사칙연산을 수행하는 `Calculator` 클래스를 구현해야 합니다. 이 클래스는 정수와 실수 연산을 모두 지원해야 합니다.

## 구현해야 할 기능들

### Calculator 클래스 메서드

1. `Add(int a, int b)` - 두 정수의 덧셈
2. `Subtract(int a, int b)` - 두 정수의 뺄셈  
3. `Multiply(int a, int b)` - 두 정수의 곱셈
4. `Divide(int a, int b)` - 두 정수의 나눗셈 (double 반환)

### 요구사항

- 모든 메서드는 `public` 접근 제어자를 가져야 합니다
- `Divide` 메서드는 `double` 타입을 반환해야 합니다
- 나눗셈에서 0으로 나누는 경우는 고려하지 않습니다
- Google Test를 사용한 단위 테스트가 포함되어 있습니다

## 빌드 및 실행

```bash
cmake . && make clean && make && ./testing
```

## 테스트

- `CalculatorTest.cpp`: 기본 기능 테스트
- `VerificationCalculatorTest.cpp`: 검증 테스트