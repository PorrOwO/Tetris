#pragma once
#include <iostream>
#include <string>

class DrawableInterface{
    protected:
        int xPos, yPos;
        std::string str;
    public:
        // costruttori
        DrawableInterface();
        DrawableInterface(int yPos, int xPos, std::string str);

        // metodi get
        int getDrawableXPos();
        int getDrawableYPos();
        std::string getDrawableString();
};