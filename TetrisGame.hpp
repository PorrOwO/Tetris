#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
// #include "Window.hpp"
#include "Menu.hpp"
// #include "Drawable.hpp"

#define MAX_LENGTH 3

class TetrisGame{
    private:
        Window win;
        Option options[MAX_LENGTH] = {Option("NEWGAME"), Option("LEADERBOARD"), Option("EXIT")};
        Menu optionBar;
        bool gameOver;
    public:
        // costruttore che inizializza una finestra e setta gameOver a false, in questo modo l'utente può eseguire dei comandi
        TetrisGame(int height, int width){
            this->win = Window(height, width); // finestra
            // Option options[MAX_LENGTH] = {Option("NEWGAME"), Option("LEADERBOARD"), Option("EXIT")};
            this->optionBar = Menu(this->win, this->options, 3); // inizializza il menu
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
                    this->win.clear();
                    break;
                default:
                    break;
            }
        };
        void updateState(){
            int highlight = 0;
            for(int i = 0; i < MAX_LENGTH; i++){    
                int yCurrent = this->options[i].getCurrentYCursorPos();
                int xCurrent = this->options[i].getCurrentXCursorPos();
                std::string str = this->options[i].getOptionTitle();
                // gestione highlight                
                if(i == highlight){
                    wattron(this->win.getWin(), A_STANDOUT);
                }
                this->win.addStringAt(yCurrent, xCurrent, str.c_str());
                wattroff(this->win.getWin(), A_STANDOUT);
            }
            // this->win.add(Drawable(1, 1, "NEWGAME"));
        };
        // metodo per aggiornare ciò che viene mostrato a schermo
        void updateDraw(){
            // implementazione opzioni
            this->win.refresh();
        };
        // ritorna lo stato del gioco
        bool isOver(){
            return this->gameOver;
        }
        // ritorna la finestra dove viene istanziato TetrisGame
        WINDOW* getWin(){
            return this->win.getWin();
        };
        Window getw(){
            return this->win;
        };
};