#include "Options.hpp"

// costruttori
Option::Option(){
    this->optionTitle = "";
}

Option::Option(std::string str){
    this->optionTitle = str;
};

// metodo per disegnare un'opzione
/*
DrawableInterface Option::createDrawableOption(){
    return DrawableInterface(this->yCursorPos, this->xCursorPos, this->optionTitle);
};
*/

// metodi get
std::string Option::getOptionTitle(){
    return this->optionTitle;
};

int Option::getYCursorPos(){
    return this->yCursorPos;
}

int Option::getXCursorPos(){
    return this->xCursorPos;
}

bool Option::getOptionOpenState(){
    return this->isOptionOpen;
};

// metodi set
void Option::setYCursorPos(int val){
    this->yCursorPos = val;
};

void Option::setXCursorPos(int val){
    this->xCursorPos = val;
};

void Option::setOptionOpenState(bool val){
    this->isOptionOpen = val;
};