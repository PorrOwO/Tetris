all: main

main: main.cpp TetrisGame.hpp Window.hpp Drawable.hpp Menu.hpp
	g++ main.cpp -lncurses -o main