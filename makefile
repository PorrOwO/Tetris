all: main

main: main.cpp TetrisGame.cpp Window.cpp Menu.cpp Options.cpp DrawableInterface.cpp MainMatrix.cpp
	g++ main.cpp TetrisGame.cpp Window.cpp Menu.cpp Options.cpp DrawableInterface.cpp MainMatrix.cpp -lncurses -o main