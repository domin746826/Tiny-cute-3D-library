run: build
	./main

build:
	g++ -o main main.cpp src/*.cpp extras/*.cpp -lX11
