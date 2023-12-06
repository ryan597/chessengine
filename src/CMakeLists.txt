cmake_minimum_required(VERSION 3.18)

project(ChessNGin
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(NGin main.cpp piece.cpp)


find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests ${CMAKE_CURRENT_SOURCE_DIR}/../tests/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# These tests need their own main
# add_executable(custom-main-tests test.cpp test-main.cpp)
# target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)
