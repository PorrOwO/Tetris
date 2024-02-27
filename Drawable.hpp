#include <iostream>
#include <cstring>
#include <string>
#include <ncurses.h>
// includere menu.hpp e fare test *?*

class Drawable{
    private:
        int xPos, yPos;
        chtype icon;
        std::string str;
    public:
        Drawable(){
            this->xPos = this->yPos = 0;
            this->icon = ' ';
        };
        Drawable(int yPos, int xPos, chtype icon){
            this->yPos = yPos;
            this->xPos = xPos;
            this->icon = icon;
        };
        Drawable(int yPos, int xPos, std::string icon){
            this->yPos = yPos;
            this->xPos = xPos;
            this->str = icon;
        };
        // get
        int getX(){
            return this->xPos;
        };
        int getY(){
            return this->yPos; 
        };
        chtype getIcon(){
            return this->icon;
        };
        std::string getString(){
            return this->str;
        };
};