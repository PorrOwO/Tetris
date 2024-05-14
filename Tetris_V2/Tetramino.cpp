#include "Tetramino.hpp"
#include "utils.hpp"

Tetramino::Tetramino(WINDOW *win): Drawable(win){
    //setX(2);
    this->x = 2;
    rotation = 0;
    type = 0;
    color = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            shape[i][j] = 0;
        }
    }
}

Tetramino::Tetramino(): Drawable(){
    this->rotation=0;
    this->type=0;
    this->color=0;
}

void Tetramino::draw() {
    wattron(this->win, COLOR_PAIR(this->color));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (shape[i][j] != 0) {
                mvwaddch(this->win, this->y + i, this->x + j, ' ' | A_REVERSE);
           }
        }
    }
    wattroff( this->win, COLOR_PAIR(this->color));
}

void Tetramino::spawn(){
    //setX(2);
    //setY(0);
    this->x = 2;
    this->y = 0;
    int randType = rand() % 7;
    switch (randType)
    {
        case 0:
            this->setShape(utils::SHAPE_1);
            this->color = utils::CYAN;
            break;
        case 1:
            this->setShape(utils::SHAPE_2);
            this->color = utils::YELLOW;
            break;
        case 2:
            this->setShape(utils::SHAPE_3);
            this->color = utils::GREEN;
            break;
        case 3:
            this->setShape(utils::SHAPE_4);
            this->color = utils::RED;
            break;
        case 4:
            this->setShape(utils::SHAPE_5);
            this->color = utils::PURPLE;
            break;
        case 5:
            this->setShape(utils::SHAPE_6);
            this->color = utils::BLUE;
            break;
        case 6:
            this->setShape(utils::SHAPE_7);
            this->color = utils::ORANGE;
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
    this->x--;
}

void Tetramino::moveRight() {
    this->x++;
}

void Tetramino::moveDown() {
    this->y++;
}

void Tetramino::moveUp() {
    this->y--;
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
