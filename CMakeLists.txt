cmake_minimum_required(VERSION 3.9)
project(marzipan)

set(CMAKE_CXX_STANDARD 11)

add_executable(marzipan main.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
target_link_libraries(marzipan Threads::Threads X11)