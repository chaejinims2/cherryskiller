#!/bin/bash

# 파일 관리자 함수들

create_file() {
    local filename="$1"
    local content="$2"
    
    if [ -z "$filename" ]; then
        echo "Error: 파일명이 필요합니다." >&2
        return 1
    fi
    
    if [ -f "$filename" ]; then
        echo "Error: 파일이 이미 존재합니다: $filename" >&2
        return 1
    fi
    
    if [ -n "$content" ]; then
        echo "$content" > "$filename"
    else
        touch "$filename"
    fi
    
    echo "파일이 생성되었습니다: $filename"
}

delete_file() {
    local filename="$1"
    
    if [ -z "$filename" ]; then
        echo "Error: 파일명이 필요합니다." >&2
        return 1
    fi
    
    if [ ! -f "$filename" ]; then
        echo "Error: 파일이 존재하지 않습니다: $filename" >&2
        return 1
    fi
    
    rm "$filename"
    echo "파일이 삭제되었습니다: $filename"
}

copy_file() {
    local source="$1"
    local destination="$2"
    
    if [ -z "$source" ] || [ -z "$destination" ]; then
        echo "Error: 소스와 대상 파일명이 필요합니다." >&2
        return 1
    fi
    
    if [ ! -f "$source" ]; then
        echo "Error: 소스 파일이 존재하지 않습니다: $source" >&2
        return 1
    fi
    
    cp "$source" "$destination"
    echo "파일이 복사되었습니다: $source -> $destination"
}

move_file() {
    local source="$1"
    local destination="$2"
    
    if [ -z "$source" ] || [ -z "$destination" ]; then
        echo "Error: 소스와 대상 파일명이 필요합니다." >&2
        return 1
    fi
    
    if [ ! -f "$source" ]; then
        echo "Error: 소스 파일이 존재하지 않습니다: $source" >&2
        return 1
    fi
    
    mv "$source" "$destination"
    echo "파일이 이동되었습니다: $source -> $destination"
}

list_files() {
    local directory="${1:-.}"
    
    if [ ! -d "$directory" ]; then
        echo "Error: 디렉토리가 존재하지 않습니다: $directory" >&2
        return 1
    fi
    
    echo "디렉토리 내용: $directory"
    ls -la "$directory"
}

file_exists() {
    local filename="$1"
    
    if [ -z "$filename" ]; then
        echo "Error: 파일명이 필요합니다." >&2
        return 1
    fi
    
    if [ -f "$filename" ]; then
        echo "true"
        return 0
    else
        echo "false"
        return 1
    fi
}

get_file_size() {
    local filename="$1"
    
    if [ -z "$filename" ]; then
        echo "Error: 파일명이 필요합니다." >&2
        return 1
    fi
    
    if [ ! -f "$filename" ]; then
        echo "Error: 파일이 존재하지 않습니다: $filename" >&2
        return 1
    fi
    
    # macOS와 Linux 모두에서 작동하는 방법
    local size
    if command -v stat >/dev/null 2>&1; then
        if stat -f%z "$filename" >/dev/null 2>&1; then
            # macOS
            size=$(stat -f%z "$filename")
        else
            # Linux
            size=$(stat -c%s "$filename")
        fi
    else
        # stat이 없는 경우 wc 사용
        size=$(wc -c < "$filename")
    fi
    
    echo "$size"
}

search_files() {
    local pattern="$1"
    local directory="${2:-.}"
    
    if [ -z "$pattern" ]; then
        echo "Error: 검색 패턴이 필요합니다." >&2
        return 1
    fi
    
    if [ ! -d "$directory" ]; then
        echo "Error: 디렉토리가 존재하지 않습니다: $directory" >&2
        return 1
    fi
    
    echo "검색 결과: '$pattern' in $directory"
    find "$directory" -name "*$pattern*" -type f 2>/dev/null
}
