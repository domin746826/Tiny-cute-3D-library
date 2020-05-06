run: build
	./main

build:
	g++ -o main main.cpp src/*.cpp -lX11
