# cage-the-shooter
Shooter game where you build your ship one piece at a time.

## Build
Run (tested in archlinux):

    mkdir build
    cd build
    cmake ..
    make

An executable will be made in `/build/app/src/` called `carrot`, libraries are statically linked currently.

Requires OpenAl, libUDev, c++17, cmake 3.14+
