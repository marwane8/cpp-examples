add_library( math_app
    adder.h
    adder.h
    multiplier.cpp
    adder.cpp
)
target_include_directories(math_app INTERFACE 
    "${CMAKE_CURRENT_SOURCE_DIR}"
)