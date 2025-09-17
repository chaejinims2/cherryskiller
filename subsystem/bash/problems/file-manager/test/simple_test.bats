#!/usr/bin/env bats

function setup() {
    # 테스트용 임시 디렉토리 생성
    TEST_DIR=$(mktemp -d)
    cd "$TEST_DIR"
    # 함수들을 현재 셸에 로드
    . "${BATS_TEST_DIRNAME}/../task.sh"
}

function teardown() {
    # 테스트 후 정리
    cd - > /dev/null
    rm -rf "$TEST_DIR"
}

@test "simple test - should create file" {
    run create_file "test.txt" "content"
    [ "$status" -eq 0 ]
    [ -f "test.txt" ]
}
