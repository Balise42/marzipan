cmake_minimum_required(VERSION 3.9)
project(marzipan)

add_subdirectory(googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")


add_executable(marzipan main.cpp graphics/ImageCanvas.cpp graphics/ImageCanvas.h graphics/Color.cpp graphics/Color.h fractales/Mandelbrot.cpp fractales/Mandelbrot.h graphics/palette/Palette.h graphics/palette/GradientPalette.cpp graphics/palette/GradientPalette.h graphics/palette/RandomPalette.cpp graphics/palette/RandomPalette.h fractales/Fractal.cpp fractales/Fractal.h fractales/Julia.h fractales/Julia.cpp graphics/palette/RepeatingGradientPalette.cpp graphics/palette/RepeatingGradientPalette.h graphics/Canvas.h graphics/palette/HistoPalette.cpp graphics/palette/HistoPalette.h graphics/Renderer.h graphics/LinearRenderer.cpp graphics/LinearRenderer.h graphics/QuadtreeRenderer.cpp graphics/QuadtreeRenderer.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
find_package(gflags REQUIRED)

target_link_libraries(marzipan Threads::Threads X11 gflags)

#TODO tidy this mess of files
add_executable(runTests tests/canvas_test.cpp graphics/ImageCanvas.cpp graphics/Color.cpp tests/mandelbrot_test.cpp fractales/Mandelbrot.cpp fractales/Fractal.cpp fractales/Fractal.h graphics/palette/RepeatingGradientPalette.cpp graphics/palette/RepeatingGradientPalette.h tests/gradient_palette_test.cpp graphics/palette/GradientPalette.cpp graphics/palette/GradientPalette.h)
target_link_libraries(runTests gtest gtest_main Threads::Threads X11 gflags)
add_test(runTests runTests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(marzipangui marzipangui.cpp graphics/ImageCanvas.cpp graphics/ImageCanvas.h graphics/Color.cpp graphics/Color.h fractales/Mandelbrot.cpp fractales/Mandelbrot.h graphics/palette/Palette.h graphics/palette/GradientPalette.cpp graphics/palette/GradientPalette.h graphics/palette/RandomPalette.cpp graphics/palette/RandomPalette.h RasterWindow.cpp RasterWindow.h fractales/Fractal.cpp fractales/Fractal.h fractales/Julia.h fractales/Julia.cpp graphics/palette/RepeatingGradientPalette.cpp graphics/palette/RepeatingGradientPalette.h graphics/Canvas.h graphics/palette/HistoPalette.cpp graphics/palette/HistoPalette.h graphics/Renderer.h graphics/LinearRenderer.cpp graphics/LinearRenderer.h graphics/QuadtreeRenderer.cpp graphics/QuadtreeRenderer.h)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
target_link_libraries(marzipangui Threads::Threads X11 Qt5::Widgets Qt5::Core gflags)