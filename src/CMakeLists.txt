set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

include_directories("../include")

add_library(storageproduct storage&product.cpp)
add_library(nodes nodes.cpp)
add_library(link link.cpp)