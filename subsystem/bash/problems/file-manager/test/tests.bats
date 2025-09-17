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

@test "should create empty file" {
    run create_file "test.txt"
    
    [ "$status" -eq 0 ]
    [ -f "test.txt" ]
    [ "$(get_file_size test.txt)" = "0" ]
}

@test "should create file with content" {
    run create_file "content.txt" "Hello World"
    
    [ "$status" -eq 0 ]
    [ -f "content.txt" ]
    [ "$(cat content.txt)" = "Hello World" ]
}

@test "should not create file if already exists" {
    create_file "existing.txt" "original"
    run create_file "existing.txt" "new content"
    
    [ "$status" -eq 1 ]
    [ "$(cat existing.txt)" = "original" ]
}

@test "should delete existing file" {
    create_file "to_delete.txt" "content"
    run delete_file "to_delete.txt"
    
    [ "$status" -eq 0 ]
    [ ! -f "to_delete.txt" ]
}

@test "should not delete non-existent file" {
    run delete_file "nonexistent.txt"
    
    [ "$status" -eq 1 ]
}

@test "should copy file" {
    create_file "source.txt" "copy me"
    run copy_file "source.txt" "dest.txt"
    
    [ "$status" -eq 0 ]
    [ -f "source.txt" ]
    [ -f "dest.txt" ]
    [ "$(cat dest.txt)" = "copy me" ]
}

@test "should move file" {
    create_file "move_me.txt" "moving content"
    run move_file "move_me.txt" "moved.txt"
    
    [ "$status" -eq 0 ]
    [ ! -f "move_me.txt" ]
    [ -f "moved.txt" ]
    [ "$(cat moved.txt)" = "moving content" ]
}

@test "should check if file exists" {
    create_file "exists.txt" "test"
    run file_exists "exists.txt"
    
    [ "$status" -eq 0 ]
    [ "$output" = "true" ]
}

@test "should return false for non-existent file" {
    run file_exists "nonexistent.txt"
    
    [ "$status" -eq 1 ]
    [ "$output" = "false" ]
}

@test "should get file size" {
    create_file "size_test.txt" "12345"
    run get_file_size "size_test.txt"
    
    [ "$status" -eq 0 ]
    # wc -c는 개행 문자를 포함하므로 6이 될 수 있음
    [ "$output" = "5" ] || [ "$output" = "6" ]
}

@test "should list files in directory" {
    create_file "file1.txt" "content1"
    create_file "file2.txt" "content2"
    run list_files "."
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"file1.txt"* ]]
    [[ "$output" == *"file2.txt"* ]]
}

@test "should search files by pattern" {
    create_file "test_file.txt" "content"
    create_file "other_file.log" "log content"
    run search_files "test"
    
    [ "$status" -eq 0 ]
    [[ "$output" == *"test_file.txt"* ]]
    [[ "$output" != *"other_file.log"* ]]
}
