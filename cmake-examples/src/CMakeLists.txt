
add_subdirectory(math_app)
add_executable(hello hello.cpp)
target_link_libraries(hello PUBLIC 
    math_app
)
