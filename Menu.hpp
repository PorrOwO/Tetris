#include <iostream>
#include <string>
#include <cstring>
#include <ncurses.h>
#include "Window.hpp"
// #include "Draw.hpp"

class Option{
    private:
        std::string option;
        int currentYCursorPos;
        int currentXCursorPos;
    public:
        Option(std::string option){
            this->option = option;
        };

        // get
        std::string getOptionTitle(){
            return this->option;
        };
        int getCurrentYCursorPos(){
            return this->currentYCursorPos;
        };
        int getCurrentXCursorPos(){
            return this->currentXCursorPos;
        };
        
        // set
        void setCurrentYCursorPos(int val){
            this->currentYCursorPos = val;
        };
        void setCurrentXCursorPos(int val){
            this->currentXCursorPos = val;
        };
};

class Menu{
    private:
        Window win; // WINDOW* ?
        Option* options;
        int numOptions;
    public:
        Menu(Window win, Option* options, int numOptions){
            this->win = win;
            this->numOptions = numOptions;
            const int incr = 2;
            int yVal = (this->win.getWin()->_maxy / 2) - incr;
            int xVal = (this->win.getWin()->_maxx) / 2;
            int offset;
            for(int i = 0; i < this->numOptions; i++){
                offset = this->options[i].getOptionTitle().length();
                this->options[i].setCurrentYCursorPos(xVal - (offset / 2));
                this->options[i].setCurrentXCursorPos(yVal);
                yVal += incr;
            }
        };
        Menu();
        //********************DANGER********************//
        void drawMenu(){
            int highlight = 0;
            for(int i = 0; i < this->numOptions; i++){
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
        };
};