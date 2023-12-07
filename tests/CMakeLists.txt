find_package(Catch2 3 REQUIRED)
# These tests can use the Catch2-provided main
add_executable(tests test.cpp)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain nginlib)
add_dependencies(tests nginlib)

include(CTest)
include(Catch)
catch_discover_tests(tests)

setup_target_for_coverage_lcov(NAME coverage
                                EXECUTABLE tests
                                EXCLUDE "/usr/*"
                                DEPENDENCIES tests nginlib)