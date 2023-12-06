find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests test.cpp)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain nginlib)

# These tests need their own main
# add_executable(custom-main-tests test.cpp test-main.cpp)
# target_link_libraries(custom-main-tests PRIVATE Catch2::Catch2)

include(CTest)
include(Catch)
catch_discover_tests(tests)