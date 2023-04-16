cmake_minimum_required(VERSION 3.20)

project(wahalez_injector)

# Set CMAKE_CXX_FLAGS to include Unicode support
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUNICODE -D_UNICODE")

# Set CMAKE_C_FLAGS to include Unicode support
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DUNICODE -D_UNICODE")

#header files directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/imgui)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories("C:\\msys64\\mingw64\\include")

#set imgui sources
set(IMGUI_BACKENDS 
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_dx11.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends/imgui_impl_win32.cpp
)
file(GLOB IMGUI_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp)
file(GLOB EXE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

#build the imgui lib
add_library(imgui 
    ${IMGUI_BACKENDS}
    ${IMGUI_SOURCES}
)   
target_link_libraries(imgui d3d11 dxgi d3dcompiler dwmapi)

add_executable(main WIN32 ${EXE_SOURCES})

#link imgui built library to main executable
target_link_libraries(main PRIVATE d3d11)
target_link_libraries(main PRIVATE imgui)



