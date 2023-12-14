cmake_minimum_required(VERSION 3.18)

project(ChessNGin
        VERSION 0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    enable_testing()
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

    include(CodeCoverage)
    append_coverage_compiler_flags()

    add_subdirectory(tests)
endif()

add_subdirectory(src)