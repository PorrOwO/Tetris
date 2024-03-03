#include <iostream>
#include <ncurses.h>
#include <cstring>
// #include "Window.hpp"
#include "Menu.hpp"
#include "MainMatrix.hpp"

#define MAX_OPTIONS 4

class TetrisGame{
    protected:
        MainMatrix matrixBoard;
        Window window;
        Option options[MAX_OPTIONS] = {Option("NEWGAME"), Option("LEADERBOARD"), Option("EXIT"), Option("")};
        Menu menu;
        bool gameOver;
    public:
        // costruttore
        // TetrisGame(Menu& menu, int height, int width);
        TetrisGame(int height, int width);

        // metodo per processare gli input
        void processInput();

        // metodo per aggiornare lo stato del gioco
        void updateState();

        // metodo per riaggiornare ciò che c'è a schermo
        void updateDraw();

        // metodi get
        bool isOver();
        Window getW();
        // Menu getMenu();
};