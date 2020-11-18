# Create the Polygon Interface library
add_library(Polygon INTERFACE)

# Create a library called "Polygon" which includes the source file "Polygon.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (Polygon Polygon.cpp)

# Make sure the compiler can find include files for our Polygon library
# when other libraries or executables link to Hello
target_include_directories (Polygon PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set Polygon compilation features to be propagated to client code.
target_compile_features(Polygon INTERFACE cxx_std_17)

# target_include_directories(Polygon INTERFACE ${CMAKE_INSTALL_INCLUDEDIR})
# Add the include paths to the Reaktoro target
target_include_directories(Polygon
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install Monotone interface library
install(TARGETS Polygon)

# EXPORT autodiffTargets

# Install autodiff header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/Polygon
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    PATTERN "CMakeLists.txt" EXCLUDE)
