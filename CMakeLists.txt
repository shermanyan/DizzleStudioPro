cmake_minimum_required(VERSION 3.23)
project(DizzleStudioPro)

set(CMAKE_CXX_STANDARD 14)

add_executable(DizzleStudioPro main.cpp Analyser.cpp Analyser.h)

target_link_libraries(DizzleStudioPro sfml-graphics sfml-audio)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)