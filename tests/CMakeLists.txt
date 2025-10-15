cmake_minimum_required(VERSION 3.11)

find_package(doctest REQUIRED)

add_executable(test_basic test_basic.cpp)
target_link_libraries(test_basic PRIVATE doctest::doctest)

enable_testing()
add_test(NAME basic_tests COMMAND test_basic)