compile: build run

build:
	gcc main.c $$(pkg-config --libs --cflags sdl3)
run:
	./a.out