cmake_minimum_required(VERSION 3.7.2)

project(Platforms)

set(CMAKE_CXX_STANDARD 11)

# add_subdirectory(libs/SFML)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
# include_directories(
#     libs/SFML/include
# )

add_executable(game src/main.cpp)

target_link_libraries(game sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
