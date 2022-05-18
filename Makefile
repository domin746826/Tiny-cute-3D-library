run: build
	./main

build:
	g++ -o main main.cpp src/*.cpp src/objects/*.cpp extras/*.cpp -lX11
