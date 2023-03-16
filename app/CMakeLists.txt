cmake_minimum_required(VERSION 3.4)

# 项目名称
set(PROJECT_NAME app)
project(${PROJECT_NAME} LANGUAGES CXX)

# 源文件
file(GLOB_RECURSE SRC_DIR_LIST "*.cc" "*.h")

add_library(${PROJECT_NAME} SHARED ${SRC_DIR_LIST})

