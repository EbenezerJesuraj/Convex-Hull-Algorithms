cmake_minimum_required(VERSION 3.10)

project(CONVEX-HULL-ALGORITHMS VERSION 1.0)

add_library(CONVEX-HULL-ALGORITHMS INTERFACE)

target_include_directories(CONVEX-HULL-ALGORITHMS INTERFACE ${CMAKE_SOURCE_DIR}/BasicIO)
target_include_directories(CONVEX-HULL-ALGORITHMS INTERFACE ${CMAKE_SOURCE_DIR}/GeomImage)
target_include_directories(CONVEX-HULL-ALGORITHMS INTERFACE ${CMAKE_SOURCE_DIR}/Line)
target_include_directories(CONVEX-HULL-ALGORITHMS INTERFACE ${CMAKE_SOURCE_DIR}/Point)
target_include_directories(CONVEX-HULL-ALGORITHMS INTERFACE ${CMAKE_SOURCE_DIR}/Polygon)
target_include_directories(CONVEX-HULL-ALGORITHMS INTERFACE ${CMAKE_SOURCE_DIR}/src)

target_compile_features(CONVEX-HULL-ALGORITHMS INTERFACE cxx_std_17)

add_subdirectory(src)
add_subdirectory(Polygon)
add_subdirectory(Point)
add_subdirectory(Line)
add_subdirectory(GeomImage)
add_subdirectory(BasicIO)
