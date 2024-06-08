cmake_minimum_required(VERSION 3.28)
project(DevTools)

set(CMAKE_CXX_STANDARD 26)

# shared/static
option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

add_library(strmanip
        strmanip/strmanip.cpp
        strmanip/strmanip.hpp
)

add_executable(touch touch/touch.cpp)

target_link_libraries(touch PRIVATE strmanip)

target_include_directories(strmanip PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/strmanip)
target_include_directories(touch PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/strmanip)
