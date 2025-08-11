compile: build run

build:
	g++ main.cpp glad.c $$(pkg-config --libs --cflags glfw3) -I include
run:
	./a.out
clean:
	rm a.out