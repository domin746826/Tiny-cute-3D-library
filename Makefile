run: build
	./main

build:
	g++ -o main main.cpp 3d/*.cpp -lX11
