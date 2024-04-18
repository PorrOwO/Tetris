main: main.o Tetris.o Classifica.o Board.o Menu.o Window.o Option.o Tetramino.o
	g++ main.o Tetris.o Classifica.o Board.o Menu.o Window.o Option.o Tetramino.o -lncurses -o main

main.o: main.cpp
	g++ main.cpp -lncurses -c

Tetris.o: Menu/Tetris.hpp
	g++ Menu/Tetris.cpp -lncurses -c

Classifica.o: Menu/Classifica.hpp
	g++ Menu/Classifica.cpp -lncurses -c

Board.o: Menu/Board.hpp
	g++ Menu/Board.cpp -lncurses -c

Menu.o: Menu/Menu.hpp
	g++ Menu/Menu.cpp -lncurses -c 

Window.o: Menu/Window.hpp
	g++ Menu/Window.cpp -lncurses -c

Option.o: Menu/Option.hpp
	g++ Menu/Option.cpp -lncurses -c

Tetramino.o: Tetramini/Tetramino.hpp
	g++ Tetramini/Tetramino.cpp -lncurses -c
