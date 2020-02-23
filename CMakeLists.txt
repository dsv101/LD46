cmake_minimum_required(VERSION 3.14)


include(FetchContent)


project(CageTheShooter  VERSION 0.0.1
                        DESCRIPTION "First game in the CAGE engine!"
                        LANGUAGES CXX)


FetchContent_Declare(
    sfml
    GIT_REPOSITORY  https://github.com/SFML/sfml
    GIT_TAG         2.5.1
)

FetchContent_MakeAvailable(sfml)

add_subdirectory(src)