# 1)

cmake_minimum_required(VERSION 3.10)

# 2)

project (HelloWorld_Addierer LANGUAGES CXX)

# 3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4)

add_library(mylib STATIC add.cpp)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#5)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE mylib)
