# test framework repository
include(FetchContent)
FetchContent_Declare(catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.1.0
)
FetchContent_MakeAvailable(catch2)

# main (temporary settings)
cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)
project(Test_of_Catch2 CXX)
add_executable(a.out main.cpp)
target_compile_options(a.out PRIVATE -Wall -Wextra)

# unit tests
enable_testing()

add_executable(CanonicalEnsembleTest CanonicalEnsembleTest.cpp)
target_compile_options(CanonicalEnsembleTest PRIVATE -Wall -Wextra)
target_link_libraries(CanonicalEnsembleTest Catch2::Catch2WithMain)
add_test(CanonicalEnsembleTest CanonicalEnsembleTest)
