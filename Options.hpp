#include <iostream>
#include <string>
// #include "DrawableInterface.hpp"
// #include "Window.hpp"

class Option{
    protected:
        std::string optionTitle;
        int yCursorPos, xCursorPos;
        bool isOptionOpen;
    public:
        // costruttori
        Option();
        Option(std::string str);

        // metodo per disegnare un'opzione
        // DrawableInterface createDrawableOption();

        // metodi get
        std::string getOptionTitle();
        int getYCursorPos();
        int getXCursorPos();
        bool getOptionOpenState();

        // metodi set
        void setYCursorPos(int val);
        void setXCursorPos(int val);
        void setOptionOpenState(bool val);
};