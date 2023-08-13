cmake_minimum_required(VERSION 3.26)

include_directories(include/base_mvc)
include_directories(include/shapes)
include_directories(include/storage)

add_executable(editor main.cpp src/shapes/Circle.cpp src/shapes/Reactangle.cpp src/shapes/TextBox.cpp)

set_target_properties(editor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


