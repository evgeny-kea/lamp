cmake_minimum_required(VERSION 3.1.0)

project(lamp)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

aux_source_directory (. sources)
aux_source_directory (./commands sources)
add_executable (lamp ${sources})

target_link_libraries(lamp Qt5::Widgets Qt5::Network)
