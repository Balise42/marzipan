# marzipan
A fractal generator. This is mostly a hobby/sandbox project where I have some fun with the coloring algorithms (of mostly Mandelbrot) and create pretty images :)

## Note: I have made no effort for that code to be runnable or even compilable on another setup than mine.

I'm running things on my machine in CLion (JetBrains C++ IDE) and my knowledge of CMake is basically limited to "CLion seems to do something with that CMakeLists that it seems happy with". Moreover, at this time, most of the rendering options are defined... at compile time.

## If you still want to give that a try:

Dependencies (must be installed on the system):
* QT5 (Core, Concurrent, Widgets)
* pthread
* X11
* gflags

To build:

* `$ cmake .`
* `$ make`

CLI version: run `./marzipan`. It creates a default rendering in "plop.bmp". The parameters of that rendering can be adjusted with some options on the CLI, run `./marzipan --help` for a (very limited) set of options. The other rendering options are set at compile time in main.cpp.

UI version: run `./marzipangui`. It creates a default rendering that can be ajusted at compile time in RasterWidget.cpp.
