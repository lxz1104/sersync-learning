cmake_minimum_required(VERSION 3.14)
project(sersync)

set(CMAKE_CXX_STANDARD 14)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

#Boost
find_package(Boost COMPONENTS
        system
        regex
        thread
        REQUIRED)
if(Boost_FOUND)
    message( STATUS "Found Boost: ${Boost_LIBRARIES}" )
    link_directories(${Boost_LIBRARY_DIRS})
endif()

#添加头文件
include_directories(
        ${INCLUDE_DIR}
)

#添加库文件
set(
        DEPENDENCIES
        ${Boost_LIBRARIES}
)

aux_source_directory(./lib SRC)
add_executable(sersync ${SRC} main.cpp)
target_link_libraries(sersync ${DEPENDENCIES} curl)