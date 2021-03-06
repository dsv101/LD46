# From: https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/src/CMakeLists.txt

# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${LD46_SOURCE_DIR}/lib/include/CAGE/*.hpp")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${LD46_SOURCE_DIR}/lib/src/*.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(cage ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(cage PUBLIC "${LD46_SOURCE_DIR}/lib/include/")

# All users of this library will need at least C++17
target_compile_features(cage PUBLIC cxx_std_17)

target_link_libraries(cage PUBLIC sfml-system sfml-window sfml-graphics sfml-audio)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/lib/include/CAGE" PREFIX "Header Files" FILES ${HEADER_LIST})
