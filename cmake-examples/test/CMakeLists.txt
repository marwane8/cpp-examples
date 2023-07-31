
add_executable( math_app_tests
    adder_test.cpp
)

target_link_libraries( math_app_tests
    math_app
    GTest::gtest_main
)

include(CTest)
include(GoogleTest)
gtest_add_tests(
    TARGET math_app_tests
)