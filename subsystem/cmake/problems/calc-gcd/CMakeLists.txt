cmake_minimum_required(VERSION 3.16)
project(problem-cmake-calc-gcd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

aux_source_directory(src SOURCE_FILES)
aux_source_directory(test TEST_SOURCE_FILES)

find_package(Threads REQUIRED)

get_filename_component(REPO_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../../../" ABSOLUTE)
add_subdirectory("${REPO_ROOT}/common/third-party/googletest" "${CMAKE_BINARY_DIR}/_deps/googletest-build")

add_executable(test_calc_gcd ${SOURCE_FILES} ${TEST_SOURCE_FILES})
target_include_directories(test_calc_gcd PRIVATE src)
target_link_libraries(test_calc_gcd PRIVATE gtest gtest_main gmock Threads::Threads)

enable_testing()
add_test(NAME AllTests COMMAND test_calc_gcd)