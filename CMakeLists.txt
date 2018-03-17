cmake_minimum_required(VERSION 3.9)
project(marzipan)

add_subdirectory(googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")


add_executable(marzipan main.cpp graphics/image_canvas.cpp graphics/image_canvas.h graphics/color.cpp graphics/color.h fractales/mandelbrot.cpp fractales/mandelbrot.h graphics/palette/palette.h graphics/palette/gradient_palette.cpp graphics/palette/gradient_palette.h graphics/palette/random_palette.cpp graphics/palette/random_palette.h fractales/fractal.cpp fractales/fractal.h fractales/julia.h fractales/julia.cpp graphics/palette/repeating_gradient_palette.cpp graphics/palette/repeating_gradient_palette.h fractales/mandelbrot_quadtree.cpp fractales/mandelbrot_quadtree.h graphics/canvas.h graphics/palette/histo_palette.cpp graphics/palette/histo_palette.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
find_package(gflags REQUIRED)

target_link_libraries(marzipan Threads::Threads X11 gflags)

#TODO tidy this mess of files
add_executable(runTests tests/canvas_test.cpp graphics/image_canvas.cpp graphics/color.cpp tests/mandelbrot_test.cpp fractales/mandelbrot.cpp fractales/fractal.cpp fractales/fractal.h graphics/palette/repeating_gradient_palette.cpp graphics/palette/repeating_gradient_palette.h tests/gradient_palette_test.cpp graphics/palette/gradient_palette.cpp graphics/palette/gradient_palette.h fractales/mandelbrot_quadtree.cpp fractales/mandelbrot_quadtree.h)
target_link_libraries(runTests gtest gtest_main Threads::Threads X11 gflags)
add_test(runTests runTests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(marzipangui marzipangui.cpp graphics/image_canvas.cpp graphics/image_canvas.h graphics/color.cpp graphics/color.h fractales/mandelbrot.cpp fractales/mandelbrot.h graphics/palette/palette.h graphics/palette/gradient_palette.cpp graphics/palette/gradient_palette.h graphics/palette/random_palette.cpp graphics/palette/random_palette.h RasterWindow.cpp RasterWindow.h fractales/fractal.cpp fractales/fractal.h fractales/julia.h fractales/julia.cpp graphics/palette/repeating_gradient_palette.cpp graphics/palette/repeating_gradient_palette.h fractales/mandelbrot_quadtree.cpp fractales/mandelbrot_quadtree.h graphics/canvas.h graphics/qpainter_canvas.cpp graphics/qpainter_canvas.h graphics/palette/histo_palette.cpp graphics/palette/histo_palette.h)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
target_link_libraries(marzipangui Threads::Threads X11 Qt5::Widgets Qt5::Core gflags)