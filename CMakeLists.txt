cmake_minimum_required(VERSION 3.15)
project(SnakeGame VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/*.c"
    "thirdparty/src/*.c"
    "thirdparty/src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE "src/*.h")

target_include_directories(${PROJECT_NAME} PRIVATE "thirdparty/include")

target_link_directories(${PROJECT_NAME} PRIVATE "thirdparty/lib")

target_link_libraries(${PROJECT_NAME} PRIVATE "GLFW/glfw3")