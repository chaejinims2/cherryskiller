GTEST_DIR="$(git -C "$TARGET_DIR" rev-parse --show-toplevel 2>/dev/null)/common/third-party/googletest"
if [[ ! -d "$GTEST_DIR" || ! -f "$GTEST_DIR/CMakeLists.txt" ]]; then
  echo "[cmake] googletest submodule not found."
  echo "       run: git submodule update --init --recursive"
  # 혹시 오프라인 캐시가 있다면 자동 복원(옵션)
  # tar -xf /path/to/cache/googletest-v1.17.0.tar.gz -C "$(dirname "$GTEST_DIR")"
  exit 2
fi

cmake -B "$TARGET_DIR/build" -S "$TARGET_DIR" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_STANDARD_REQUIRED=ON -DCMAKE_CXX_EXTENSIONS=OFF
cmake --build "$TARGET_DIR/build"
cmake --test "$TARGET_DIR/build"
cmake --install "$TARGET_DIR/build"