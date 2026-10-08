cmake_minimum_required(VERSION 3.20)
project(DS2026)

set(CMAKE_CXX_STANDARD 11)

# 包含 mstl 目录，让编译器找到 vector.h
include_directories(${PROJECT_SOURCE_DIR})

# 把 main.cpp 编译成可执行文件
add_executable(DS2026 main.cpp)