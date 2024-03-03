#include "DrawableInterface.hpp"

DrawableInterface::DrawableInterface(){
    this->xPos = this->yPos = 0;
    this->str = "";
};

DrawableInterface::DrawableInterface(int yPos, int xPos, std::string str){
    this->yPos = yPos;
    this->xPos = xPos;
    this->str = str;
};

int DrawableInterface::getDrawableXPos(){
    return this->xPos;
};
int DrawableInterface::getDrawableYPos(){
    return this->yPos;
};
std::string DrawableInterface::getDrawableString(){
    return this->str;
};