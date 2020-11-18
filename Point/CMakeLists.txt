# Create the Point Interface library
add_library(Point INTERFACE)

# Create a library called "Point" which includes the source file "Point.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (Point Point.cpp)

# Make sure the compiler can find include files for our Point library
# when other libraries or executables link to Hello
target_include_directories (Point PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set Point compilation features to be propagated to client code.
target_compile_features(Point INTERFACE cxx_std_17)

# target_include_directories(Point INTERFACE ${CMAKE_INSTALL_INCLUDEDIR})
# Add the include paths to the Reaktoro target
target_include_directories(Point
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install Monotone interface library
install(TARGETS Point)

# EXPORT autodiffTargets

# Install autodiff header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/Point
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    PATTERN "CMakeLists.txt" EXCLUDE)
