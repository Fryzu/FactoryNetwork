set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

include_directories("../include")

add_library(date date.cpp)
add_executable(kalendarz main.cpp )

target_link_libraries(kalendarz date)