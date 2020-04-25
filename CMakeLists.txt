cmake_minimum_required(VERSION 3.9)
project(marzipan)

#add_subdirectory(googletest)
#enable_testing()
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(X11 REQUIRED)
find_package(gflags REQUIRED)
find_package(Qt5Concurrent REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")

#TODO: eventually readd to executables fractales/MartinMandelbrot.cpp fractales/MartinMandelbrot.h
add_executable(marzipan main.cpp graphics/ImageCanvas.cpp graphics/ImageCanvas.h graphics/Color.cpp graphics/Color.h fractales/Mandelbrot.cpp fractales/Mandelbrot.h graphics/palette/Palette.h graphics/palette/GradientPalette.cpp graphics/palette/GradientPalette.h graphics/palette/RandomPalette.cpp graphics/palette/RandomPalette.h fractales/Fractal.cpp fractales/Fractal.h fractales/Julia.h fractales/Julia.cpp graphics/palette/RepeatingGradientPalette.cpp graphics/palette/RepeatingGradientPalette.h graphics/Canvas.h graphics/palette/HistoPalette.cpp graphics/palette/HistoPalette.h graphics/Renderer.h graphics/LinearRenderer.cpp graphics/LinearRenderer.h graphics/QuadtreeRenderer.cpp graphics/QuadtreeRenderer.h fractales/ContinuousMandelbrot.cpp fractales/ContinuousMandelbrot.h graphics/palette/ContinuousPalette.cpp graphics/palette/ContinuousPalette.h graphics/LinearRendererThreading.cpp graphics/LinearRendererThreading.h graphics/ColoredPoint.cpp graphics/ColoredPoint.h fractales/OrbitMandelbrot.cpp fractales/OrbitMandelbrot.h graphics/palette/ContinuousFixedPalette.cpp graphics/palette/ContinuousFixedPalette.h fractales/MandelbrotExperiments.cpp fractales/MandelbrotExperiments.h fractales/orbits/Orbit.h fractales/orbits/PointOrbit.cpp fractales/orbits/PointOrbit.h fractales/orbits/LineOrbit.cpp fractales/orbits/LineOrbit.h fractales/orbits/BitmapOrbit.cpp fractales/orbits/BitmapOrbit.h fractales/orbits/util/BitmapMapComputer.cpp fractales/orbits/util/BitmapMapComputer.h protobuf/marzipanstate.pb.cc protobuf/marzipanstate.pb.h fractales/MpComplex.cpp fractales/MpComplex.h)
find_package(Protobuf REQUIRED)
target_link_libraries(marzipan Threads::Threads X11 gflags Qt5::Concurrent protobuf)

#TODO tidy this mess of files
#add_executable(runTests tests/canvas_test.cpp graphics/ImageCanvas.cpp graphics/Color.cpp tests/mandelbrot_test.cpp fractales/Mandelbrot.cpp fractales/Fractal.cpp fractales/Fractal.h graphics/palette/RepeatingGradientPalette.cpp graphics/palette/RepeatingGradientPalette.h tests/gradient_palette_test.cpp graphics/palette/GradientPalette.cpp graphics/palette/GradientPalette.h fractales/MandelbrotExperiments.cpp fractales/MandelbrotExperiments.h)
#target_link_libraries(runTests gtest gtest_main Threads::Threads X11 gflags)
#add_test(runTests runTests)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(marzipangui marzipangui.cpp graphics/ImageCanvas.cpp graphics/ImageCanvas.h graphics/Color.cpp graphics/Color.h fractales/Mandelbrot.cpp fractales/Mandelbrot.h graphics/palette/Palette.h graphics/palette/GradientPalette.cpp graphics/palette/GradientPalette.h graphics/palette/RandomPalette.cpp graphics/palette/RandomPalette.h RasterWidget.cpp RasterWidget.h fractales/Fractal.cpp fractales/Fractal.h fractales/Julia.h fractales/Julia.cpp graphics/palette/RepeatingGradientPalette.cpp graphics/palette/RepeatingGradientPalette.h graphics/Canvas.h graphics/palette/HistoPalette.cpp graphics/palette/HistoPalette.h graphics/Renderer.h graphics/LinearRenderer.cpp graphics/LinearRenderer.h graphics/QuadtreeRenderer.cpp graphics/QuadtreeRenderer.h fractales/ContinuousMandelbrot.cpp fractales/ContinuousMandelbrot.h graphics/palette/ContinuousPalette.cpp graphics/palette/ContinuousPalette.h graphics/LinearRendererThreading.cpp graphics/LinearRendererThreading.h graphics/ColoredPoint.cpp graphics/ColoredPoint.h fractales/OrbitMandelbrot.cpp fractales/OrbitMandelbrot.h graphics/palette/ContinuousFixedPalette.cpp graphics/palette/ContinuousFixedPalette.h fractales/MandelbrotExperiments.cpp fractales/MandelbrotExperiments.h fractales/orbits/Orbit.h fractales/orbits/PointOrbit.cpp fractales/orbits/PointOrbit.h fractales/orbits/LineOrbit.cpp fractales/orbits/LineOrbit.h fractales/orbits/BitmapOrbit.cpp fractales/orbits/BitmapOrbit.h fractales/orbits/util/BitmapMapComputer.cpp fractales/orbits/util/BitmapMapComputer.h RasterWindow.cpp RasterWindow.h protobuf/marzipanstate.pb.cc protobuf/marzipanstate.pb.h fractales/MpComplex.cpp fractales/MpComplex.h)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Concurrent REQUIRED)
find_package(Protobuf REQUIRED)
find_package(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(marzipangui Threads::Threads X11 Qt5::Widgets Qt5::Core Qt5::Concurrent gflags protobuf ${ImageMagick_LIBRARIES} mpfr gmp)