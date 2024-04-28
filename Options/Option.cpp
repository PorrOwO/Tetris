#include "Option.hpp"

Option::Option(std::string title) {
    this->title = title;
}

std::string Option::getTitle() {
    return this->title;
}

int Option::getX() {
    return this->xPos;
}

int Option::getY() {
    return this->yPos;
}

void Option::setX(int val) {
    this->xPos = val;
}

void Option::setY(int val) {
    this->yPos = val;
}