cmake_minimum_required(VERSION 3.16)
project(Hello VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG 4a1a299b206ba250a4318f74938ea67c75c3c0c9
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()

