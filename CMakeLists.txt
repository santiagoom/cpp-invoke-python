cmake_minimum_required(VERSION 3.17)
project(cpp-invoke-python)

set(CMAKE_CXX_STANDARD 14)


# 添加 Python 的 include 目录，找到自己装 python 的目录，Python 默认安装路径在：“C:\Users\你自己的用户名\AppData\Local\Programs\Python”
include_directories(D:\\envs\\anaconda32002\\include)
#include_directories(D:\\envs\\anaconda32002\\Lib\\site-packages\\torch\\include\\pybind11)

# 添加 Python 的 lib 库，同样找到 python 安装目录下的 libs 文件夹中的 python37.lib 文件
link_libraries(D:\\envs\\anaconda32002\\libs\\python37.lib)


find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
#find_package(Python REQUIRED)



message(STATUS "print_all_variables------------------------------------------{")
get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()
message(STATUS "print_all_variables------------------------------------------}")





add_executable(cpp_python cpp_python.cpp)
add_executable(cpp_sys cpp_sys.cpp)
#add_executable(great_function_from_python great_function_from_python.cpp)

#add_executable(test_add test_add.cpp)

add_executable(demo demo.cpp)
add_executable(demo2 demo2.cpp)
add_executable(ConsoleApplication1 ConsoleApplication1.cpp)




#cmake_minimum_required(VERSION 2.8)
#
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#
## Configure built shared libraries in top-level lib directory
#set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)
#
#find_package (Python2 COMPONENTS Interpreter NumPy)

# Build the shared libraries
#add_library (frvt_11_null_001 SHARED nullimplfrvt11.cpp)
#target_include_directories (frvt_11_null_001 PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/../include
#        ${CMAKE_CURRENT_SOURCE_DIR}/../../../common/src/include
#        )
#target_link_libraries(frvt_11_null_001 PUBLIC Python2::NumPy)