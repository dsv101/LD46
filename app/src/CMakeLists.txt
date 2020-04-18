# From: https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/src/CMakeLists.txt

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${LD46_SOURCE_DIR}/app/include/*.hpp")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${LD46_SOURCE_DIR}/app/src/*.cpp")

add_executable(carrot ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, the header files above are not part of the build process
target_include_directories(carrot PRIVATE "${LD46_SOURCE_DIR}/app/include/")

target_compile_features(carrot PRIVATE cxx_std_17)

target_link_libraries(carrot PRIVATE cage)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/app/include" PREFIX "Header Files" FILES ${HEADER_LIST})
