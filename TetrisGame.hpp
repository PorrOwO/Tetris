#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "Window.hpp"

class TetrisGame{
    private:
        Window win;
        bool gameOver;
    public:
        // costruttore che inizializza una finestra e setta gameOver a false, in questo modo l'utente può eseguire dei comandi
        TetrisGame(int height, int width){
            this->win = Window(height, width);
            this->win.init();
            this->win.addBorder();
            this->gameOver = false;
        };
        // metodo per processare i vari tipi di input
        void processInput(){
            keypad(this->win.getWin(), true);
            chtype input = this->win.getInput();
            switch(input){
                case 'q': // viene messo a cascata perchè con l'or non funziona
                case 'Q':
                    this->gameOver = true;
                    break;
                default:
                    break;
            }
        };
        void updateState(){
            // update
        };
        // metodo per aggiornare ciò che viene mostrato a schermo
        void updateDraw(){
            // implementazione opzioni
            this->win.refresh();
        };
        // ritorna lo stato del gioco
        bool isOver(){
            return this->gameOver;
        };
        // ritorna la finestra dove viene istanziato TetrisGame
        WINDOW* getWin(){
            return this->win.getWin();
        };
};