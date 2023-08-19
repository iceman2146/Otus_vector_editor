cmake_minimum_required(VERSION 3.26)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(EDITOR_project VERSION ${PROJECT_VESRION})

configure_file(version.h.in version.h) 


include_directories(include)
include_directories(include/base_mvc)
include_directories(include/shapes)
include_directories(include/storage)

add_executable(editor main.cpp src/shapes/Circle.cpp src/shapes/Reactangle.cpp src/shapes/TextBox.cpp)
add_library(lib src/ver.cpp)
target_include_directories(lib 
    PRIVATE "${CMAKE_BINARY_DIR}"
    )
target_link_libraries(editor PRIVATE
lib)  

set_target_properties(lib editor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)
include (CPack)

