cmake_minimum_required(VERSION 3.14)

project(ChessNGin
        VERSION 0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wold-style-cast -Wcast-align
-Woverloaded-virtual -Wconversion -Wsigh-conversion -Wmisleading-indentation -Wduplicated-cond
-Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion
-Wformat=2)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    enable_testing()
    add_compile_options(-Werror -Wno-unused-parameter)
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

    # Download CPM.cmake
    file(
        DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
        ${CMAKE_SOURCE_DIR}/cmake/CPM.cmake
        EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
        SHOW_PROGRESS
    )

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
         ${CMAKE_SOURCE_DIR}/cmake/CodeCoverage.cmake
         SHOW_PROGRESS
    )
    include(CodeCoverage)
    append_coverage_compiler_flags()

    add_subdirectory(tests)
endif()

add_subdirectory(src)