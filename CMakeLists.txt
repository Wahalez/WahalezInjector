cmake_minimum_required(VERSION 3.20)

project(imgui_lrn1)

#header files directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/imgui)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#set imgui sources
set(IMGUI_BACKENDS 
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_dx11.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_win32.cpp
)
file(GLOB IMGUI_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp)

#build the imgui lib
add_library(imgui 
    ${IMGUI_BACKENDS}
    ${IMGUI_SOURCES}
)   

add_executable(main src/main.cpp)

#link imgui built library to main executable
target_link_libraries(main PRIVATE d3d11)
target_link_libraries(main PRIVATE imgui)



