# Tiny-cute-3D-library

![20220522_00h21m15s_grim](https://user-images.githubusercontent.com/52156158/169670826-420ed5a6-dc87-4e9f-8fa3-71691c60408e.png)


Tiny cute 3D library is small software 3D renderer, designed to be simple in use and possible to install on anything (that is why rendering is software only)
<br><br>
**WORK IN PROGRESS**

## Compiling
```
make
```

## Porting
To make it working on sth else, just write low level graphical functions for your devices in src/primitives.cpp (your device must support C++ STL libraries and dynamic C++ memory allocation)

## Usage

Example usage is shown in main.cpp and extras/*, they are customized to use on X11 (but they work on XWayland too)

