# Create the GeomImage Interface library
add_library(GeomImage INTERFACE)
G
# Create a library called "GeomImage" which includes the source file "GeomImage.cpp".
# The extension is already found. Any number of sources could be listed here.
add_library (GeomImage GeomImage.cpp)

# Make sure the compiler can find include files for our GeomImage library
# when other libraries or executables link to Hello
target_include_directories (GeomImage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set GeomImage compilation features to be propagated to client code.
target_compile_features(GeomImage INTERFACE cxx_std_17)

# target_include_directories(GeomImage INTERFACE ${CMAKE_INSTALL_INCLUDEDIR})
# Add the include paths to the Reaktoro target
target_include_directories(GeomImage
    INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Install Monotone interface library
install(TARGETS GeomImage)

# EXPORT autodiffTargets

# Install autodiff header files
install(DIRECTORY ${PROJECT_SOURCE_DIR}/GeomImage
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} COMPONENT headers
    PATTERN "CMakeLists.txt" EXCLUDE)
