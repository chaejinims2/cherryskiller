cmake_minimum_required(VERSION 3.8)
project(cpp_calc)

aux_source_directory(src SOURCE_FILES)
aux_source_directory(test TEST_SOURCE_FILES)

find_package (Threads)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(testing ${SOURCE_FILES} ${TEST_SOURCE_FILES})
target_compile_features(testing PUBLIC cxx_std_20)
set_target_properties(testing PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(testing ${GTEST_BOTH_LIBRARIES})
target_link_libraries(testing Threads::Threads)


add_test(AllTests testing)