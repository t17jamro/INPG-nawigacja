cmake_minimum_required(VERSION 3.13)
project(INPG_Nawigacja)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Werror -Wpedantic -pedantic-errors)

include_directories(
        include
)

set(SOURCE_FILES
        src/INPG_Nawigacja.cpp
        )

add_executable(INPG_Nawigacja__debug ${SOURCE_FILES} INPG_Nawigacja.cpp)

# == Unit testing using Google Testing Framework ==

set(SOURCES_FILES_TESTS
        test/test_INPG_Nawigacja.cpp
        )

add_executable(INPG_Nawigacja__test ${SOURCE_FILES} ${SOURCES_FILES_TESTS} test/main_gtest.cpp)

target_include_directories(INPG_Nawigacja__test PUBLIC
        ../../googletest-master/googlemock/include
        ../../googletest-master/googletest/include
        )

add_subdirectory(../../googletest-master googletest-master)

target_link_libraries(INPG_Nawigacja__test gmock)
