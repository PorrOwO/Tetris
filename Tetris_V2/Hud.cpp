#include "Hud.hpp"
//#include "Tetramino.hpp"


Hud::Hud(WINDOW *hudwin, int punteggio, int multiplier)
{
    this->hudwin=hudwin;
    this->punteggio=punteggio;
    //this->nome=nome;
    this->multiplier=multiplier;
    this->shapeWin= newwin(6, 6, 0, 0);
    //this->nexshape.spawn();
    this->lines=0;
    
};
Hud::Hud()
{
    this->hudwin=nullptr;
    this->punteggio=10;
    //this->nome=nome;
    this->multiplier=1;
    this->nexshape.spawn();
    this->lines=0;
};
Hud::~Hud(){};

void Hud::setScore(int punteggio)
{
    this->punteggio=punteggio;
    
} 
void Hud::computeScore()
{
    this->punteggio+=(this->lines*this->multiplier)+(100*this->lines);
}
/*void Hud::setName(char nome)
{
    this->nome=nome;
}*/
/*
void Hud::setnextShape(Tetramino nexshape)
{
    this->nexshape=nexshape;
}*/
void Hud::nextPiece(Tetramino nexshape)
{
    this->nexshape=nexshape;
    this->nexshape.spawn();
    //this->nexshape.draw();
}
WINDOW* Hud::nextshapeWin()
{
    return this->shapeWin;
}
void Hud::printNextShape(){
    this->nexshape.draw();
}
void Hud::printHUD()
{
    //box(this->hudwin, 0, 0);
    mvwprintw(this->hudwin, 1, 1, "Punteggio: %d", this->punteggio);
    //mvwprintw(this->hudwin ,0, 1, "Nome: %c", this->nome);
    //box(this->shapeWin, 0, 0);
    //wrefresh(this->shapeWin);
    mvwprintw(this->hudwin, 2, 1,"");
    //this->nexshape.draw();
    //stampa i comandi
    mvwprintw(this->hudwin, 10, 1, "Comandi:");
    mvwprintw(this->hudwin, 11, 1, "a: Sinistra");
    mvwprintw(this->hudwin, 12, 1, "d: Destra");
    mvwprintw(this->hudwin, 13, 1, "w: Ruota");
    mvwprintw(this->hudwin, 14, 1, "s: Giu");
    mvwprintw(this->hudwin, 15, 1, "q: Esci");
    //wrefresh(this->shapeWin);
    wrefresh(this->hudwin);

}
void Hud::destroyHUD()
{
    wclear(this->hudwin);
    wclear(this->shapeWin);
    wrefresh(this->hudwin);
    wrefresh(this->shapeWin);
    //wclear(this->shapeWin);
    //wrefresh(this->shapeWin);

}
/*void printHUD(WINDOW* hudwin, int punteggio)
{
    //mvprintw(0, 0, "Nome: %c", nome);
    mvprintw(0, 1, "Punteggio: %d", punteggio);
    move(0, 5);
    //mvprintw(0, 5, "Prossimo pezzo: %d", nextshape);


}*/

void Hud::setLines(int lines)
{
    this->lines=lines;
}

int Hud::getLines()
{
    return this->lines;
}

int Hud::getScore()
{
    return this->punteggio;
}

Tetramino Hud::getNexshape()
{
    return this->nexshape;
}