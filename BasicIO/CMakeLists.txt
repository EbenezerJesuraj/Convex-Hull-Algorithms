# Create the BasicIO Interface library
add_library(BasicIO INTERFACE)

# Create a library called "BasicIO" which includes the source file "BasicIO.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (BasicIO BasicIO.cpp)

# Make sure the compiler can find include files for our BasicIO library
# when other libraries or executables link to Hello
target_include_directories (BasicIO PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set BasicIO compilation features to be propagated to client code.
target_compile_features(BasicIO INTERFACE cxx_std_17)

# target_include_directories(BasicIO INTERFACE ${CMAKE_INSTALL_INCLUDEDIR})
# Add the include paths to the Reaktoro target
target_include_directories(BasicIO
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install Monotone interface library
install(TARGETS BasicIO)

# EXPORT autodiffTargets

# Install autodiff header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/BasicIO
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    PATTERN "CMakeLists.txt" EXCLUDE)
