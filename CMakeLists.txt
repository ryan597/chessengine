cmake_minimum_required(VERSION 3.14)

project(ChessNGin
        VERSION 0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Wpedantic -Wno-unused-parameter -Wnon-virtual-dtor)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    enable_testing()
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

    include(CPM)
    CPMAddPackage(
        NAME Catch2
        GIT_REPOSITORY "https://github.com/catchorg/Catch2.git"
        GIT_TAG "v3.5.0"
    )
    list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/extras")

    # Code Coverage - download and append compiler flags
    file(DOWNLOAD
         https://raw.githubusercontent.com/bilke/cmake-modules/master/CodeCoverage.cmake
         ${CMAKE_SOURCE_DIR}/cmake/CodeCoverage.cmake)
    include(CodeCoverage)
    append_coverage_compiler_flags()

    add_subdirectory(tests)
endif()

add_subdirectory(src)