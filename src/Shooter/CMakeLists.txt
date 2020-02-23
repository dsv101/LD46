# From: https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/src/CMakeLists.txt

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CageTheShooter_SOURCE_DIR}/include/Shooter/*.hpp")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CageTheShooter_SOURCE_DIR}/src/Shooter/*.cpp")

add_executable(shooter ${SOURCE_LIST} ${HEADER_LIST})

target_compile_features(shooter PRIVATE cxx_std_17)

target_link_libraries(shooter PRIVATE cage)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include/Shooter" PREFIX "Header Files" FILES ${HEADER_LIST})
