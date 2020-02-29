# From: https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/src/CMakeLists.txt

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CageTheShooter_SOURCE_DIR}/app/include/Shooter/*.hpp")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CageTheShooter_SOURCE_DIR}/app/src/*.cpp")

add_executable(shooter ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, the header files above are not part of the build process
target_include_directories(shooter PRIVATE "${CageTheShooter_SOURCE_DIR}/app/include/")

target_compile_features(shooter PRIVATE cxx_std_17)

target_link_libraries(shooter PRIVATE cage)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/app/include/Shooter" PREFIX "Header Files" FILES ${HEADER_LIST})
