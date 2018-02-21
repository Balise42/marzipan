cmake_minimum_required(VERSION 3.9)
project(marzipan)

add_subdirectory(googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS -Wall)

add_executable(marzipan main.cpp graphics/canvas.cpp graphics/canvas.h graphics/color.cpp graphics/color.h fractales/mandelbrot.cpp fractales/mandelbrot.h graphics/palette/palette.h graphics/palette/gradient_palette.cpp graphics/palette/gradient_palette.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
target_link_libraries(marzipan Threads::Threads X11)

add_executable(runTests tests/canvas_test.cpp graphics/canvas.cpp graphics/color.cpp tests/mandelbrot_test.cpp fractales/mandelbrot.cpp)
target_link_libraries(runTests gtest gtest_main Threads::Threads X11)
add_test(runTests runTests)