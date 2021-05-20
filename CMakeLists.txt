cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME StackList) 
project(${PROJECT_NAME})
 
set(ExceptionLib ExceptionLib)
set(ListLib ListLib)
set(StackList StackList)
set(StackListLib StackListLib)
set(StackListTest StackListTest)


set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE) 
 set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ExceptionLib)
add_subdirectory(ExceptionLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(ListLib)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackListLib)
add_subdirectory(StackList)
add_subdirectory(StackListLib)
add_subdirectory(StackListTest)
add_subdirectory(gtest)
