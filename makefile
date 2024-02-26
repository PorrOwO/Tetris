all: main

main: main.cpp TetrisGame.hpp Window.hpp
	g++ main.cpp -lncurses -o main