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

@test "Verification test - should handle complex file operations" {
    # 복잡한 파일 작업 시나리오 테스트
    create_file "doc1.txt" "Document 1 content"
    create_file "doc2.txt" "Document 2 content"
    
    # 파일 복사
    copy_file "doc1.txt" "backup_doc1.txt"
    
    # 파일 존재 확인
    run file_exists "backup_doc1.txt"
    [ "$status" -eq 0 ]
    [ "$output" = "true" ]
    
    # 파일 크기 확인
    run get_file_size "doc1.txt"
    [ "$status" -eq 0 ]
    # wc -c는 개행 문자를 포함하므로 18 또는 19가 될 수 있음
    [ "$output" = "18" ] || [ "$output" = "19" ]  # "Document 1 content"의 길이
    
    # 파일 이동
    move_file "doc2.txt" "renamed_doc2.txt"
    
    # 원본 파일이 없어졌는지 확인
    run file_exists "doc2.txt"
    [ "$status" -eq 1 ]
    [ "$output" = "false" ]
    
    # 새 이름으로 파일이 있는지 확인
    run file_exists "renamed_doc2.txt"
    [ "$status" -eq 0 ]
    [ "$output" = "true" ]
}