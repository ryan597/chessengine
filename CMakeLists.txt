cmake_minimum_required(VERSION 3.14)

project(ChessNGin
        VERSION 0.1
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    enable_testing()
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
    if(MSVC)
        add_compile_options(/W4)
    else()
        # Flags to be added once refactor is done
        #-Werror
        add_compile_options(-Wno-unused-parameter)
        
        # Code Coverage - download and append compiler flags
        file(DOWNLOAD
             https://raw.githubusercontent.com/bilke/cmake-modules/master/CodeCoverage.cmake
             ${CMAKE_SOURCE_DIR}/cmake/CodeCoverage.cmake
             SHOW_PROGRESS
        )
        include(CodeCoverage)
        append_coverage_compiler_flags()
    endif()

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
endif()

if(CMAKE_PROJECT_NAME STREQUAL ChessNGin AND BUILD_TESTING)
    message(STATUS "Testing enabled")
    enable_testing()
    add_subdirectory(tests)
endif()

add_subdirectory(src)