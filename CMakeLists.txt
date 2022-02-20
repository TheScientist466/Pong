cmake_minimum_required(VERSION 3.0.0)
project(Pong VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(SFML REQUIRED graphics window system audio)

file(
    GLOB
    source_files
    "src/*.cpp"
    "src/window/*.cpp"
    "src/Bars/*.cpp"
)

add_executable(${PROJECT_NAME} ${source_files})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window sfml-audio)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
