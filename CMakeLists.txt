cmake_minimum_required(VERSION 3.10)
project(GodDrinksCpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 如果有头文件，包含头文件目录
include_directories(include)

# 定义可执行文件
add_executable(GodDrinksCpp src/GodDrinksCpp.cpp)

# 如果有其他源文件，也需要添加
# add_executable(GodDrinksCpp src/GodDrinksCpp.cpp src/otherFile.cpp)

# 如果需要链接到某些库
# target_link_libraries(GodDrinksCpp someLibrary)

