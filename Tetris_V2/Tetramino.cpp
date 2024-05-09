#include "Tetramino.hpp"
#include "utils.hpp"

Tetramino::Tetramino(WINDOW *win) {
    this->win = win;
    this->x = 2;
    this->y = 0;
    // this->x = (this->win->_maxx / 2) - 2;
    // this->y = (this->win->_maxy / 2) - (utils::BOARD_HEIGHT / 2);
    rotation = 0;
    type = 0;
    color = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            shape[i][j] = 0;
        }
    }
}

Tetramino::~Tetramino() {
}

void Tetramino::draw() {
    wattron(win, COLOR_PAIR(color));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j] != 0) {
                mvwaddch(win, y + i, x + j, ' ' | A_REVERSE);
            }
        }
    }
    wattroff(win, COLOR_PAIR(color));
}
void Tetramino::spawn(){
    this->x = 2;
    this->y = 0;
    int randType = rand() % 7;
    switch (randType)
    {
        case 0:
            this->setShape(utils::SHAPE_1);
            break;
        case 1:
            this->setShape(utils::SHAPE_2);
            break;
        case 2:
            this->setShape(utils::SHAPE_3);
            break;
        case 3:
            this->setShape(utils::SHAPE_4);
            break;
        case 4:
            this->setShape(utils::SHAPE_5);
            break;
        case 5:
            this->setShape(utils::SHAPE_6);
            break;
        case 6:
            this->setShape(utils::SHAPE_7);
            break;
        default:
            break;
    }
}

// ruota il tetramino in senso orario
void Tetramino::rotateLeft() {
    int temp[4][4];
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = shape[i][j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            shape[i][j] = temp[3 - j][i];
        }
    }
    rotation = (rotation + 1) % 4;
}

// ruota il tetramino in senso antiorario
void Tetramino::rotateRight() {
    int temp[4][4];
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = shape[i][j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            shape[i][j] = temp[j][3 - i];
        }
    }
    rotation = (rotation + 3) % 4;
}

void Tetramino::moveLeft() {
    x--;
}

void Tetramino::moveRight() {
    x++;
}

void Tetramino::moveDown() {
    y++;
}

void Tetramino::moveUp() {
    y--;
}

void Tetramino::setX(int x) {
    this->x = x;
}

void Tetramino::setY(int y) {
    this->y = y;
}

void Tetramino::setRotation(int rotation) {
    this->rotation = rotation;
}

void Tetramino::setType(int type) {
    this->type = type;
}

void Tetramino::setColor(int color) {
    //this->color = color;
    srand(time(NULL));
    this->color=(rand()%7)+1;
}

void Tetramino::setShape(const int shape[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->shape[i][j] = shape[i][j];
        }
    }
}

int Tetramino::getX() {
    return x;
}

int Tetramino::getY() {
    return y;
}

int Tetramino::getRotation() {
    return rotation;
}

int Tetramino::getType() {
    return type;
}

int Tetramino::getColor() {
    return color;
}

int Tetramino::getBlockValue(int x, int y) {
    return shape[x][y];
}
