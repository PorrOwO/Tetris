#include "Drawable.hpp"

Drawable::Drawable(WINDOW* win) {
    this->win = win;
    this->x = 0;
    this->y = 0;
}

Drawable::Drawable() {
    this->win = nullptr;
    this->x = 0;
    this->y = 0;
}

void Drawable::draw() {
    // do nothing
}

Drawable::~Drawable() {
    // do nothing
}

int Drawable::getX() {
    return this->x;
}

int Drawable::getY() {
    return this->y;
}

void Drawable::setX(int x) {
    this->x = x;
}

void Drawable::setY(int y) {
    this->y = y;
}

WINDOW* Drawable::getWin() {
    return this->win;
}

void Drawable::setWin(WINDOW* win) {
    this->win = win;
}
