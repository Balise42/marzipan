cmake_minimum_required(VERSION 3.9)
project(marzipan)

add_subdirectory(googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)

add_executable(marzipan main.cpp Canvas.cpp Canvas.h Color.cpp Color.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
target_link_libraries(marzipan Threads::Threads X11)

add_executable(runTests canvas_test.cpp Canvas.cpp Color.cpp)
target_link_libraries(runTests gtest gtest_main Threads::Threads X11)
add_test(runTests runTests)