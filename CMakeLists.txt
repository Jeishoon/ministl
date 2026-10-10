cmake_minimum_required(VERSION 3.20)
project(ministl CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.2)
FetchContent_MakeAvailable(Catch2)

option(ENABLE_SANITIZERS "Build with ASan/UBSan" ON)

add_compile_options(-Wall -Wextra -Wpedantic)
if(ENABLE_SANITIZERS)
  add_compile_options(-fsanitize=address,undefined)
  add_link_options(-fsanitize=address,undefined)
endif()

add_executable(tests src/int_vector.cpp tests/test_int_vector.cpp)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)