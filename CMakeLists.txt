cmake_minimum_required(VERSION 4.3)
project(MyVector)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyVector myVect.cpp myVect.h main.cpp)

#Dont work in my CLion
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address -g")
#set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=address")