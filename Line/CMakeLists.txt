# Create the Line Interface library
add_library(Line INTERFACE)

# Create a library called "Line" which includes the source file "Line.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (Line Line.cpp)

# Make sure the compiler can find include files for our Line library
# when other libraries or executables link to Hello
target_include_directories (Line PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set Line compilation features to be propagated to client code.
target_compile_features(Line INTERFACE cxx_std_17)

# target_include_directories(Line INTERFACE ${CMAKE_INSTALL_INCLUDEDIR})
# Add the include paths to the Reaktoro target
target_include_directories(Line
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install Monotone interface library
install(TARGETS Line)

# EXPORT autodiffTargets

# Install autodiff header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/Line
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    PATTERN "CMakeLists.txt" EXCLUDE)
