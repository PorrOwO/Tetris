#include "Hud.hpp"
//#include "Tetramino.hpp"


Hud::Hud(WINDOW *hudwin, int punteggio, int multiplier)
{
    this->hudwin=hudwin;
    this->punteggio=punteggio;
    this->multiplier=multiplier;
    this->shapeWin= newwin(6, 6, 3, 3);
    this->lines=0;
    
};
Hud::Hud()
{
    this->hudwin=nullptr;
    this->punteggio=10;
    this->multiplier=1;
    this->nexshape.spawn(3, 4);
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
void Hud::nextPiece(Tetramino nexshape)
{
    this->nexshape=nexshape;
    this->nexshape.spawn(3,4);
}

void Hud::printNextShape(){
    this->nexshape.draw();
}
void Hud::printHUD()
{
    //stampa il punteggio
    mvwprintw(this->hudwin, 1, 1, "Punteggio: %d", this->punteggio);
    //stampa il prossimo pezzo
    mvwprintw(this->hudwin, 3, 1, "Prossimo pezzo:");
    //stampa i comandi
    mvwprintw(this->hudwin, 10, 1, "Comandi:");
    mvwprintw(this->hudwin, 11, 1, "a: Sinistra");
    mvwprintw(this->hudwin, 12, 1, "d: Destra");
    mvwprintw(this->hudwin, 13, 1, "w: Ruota");
    mvwprintw(this->hudwin, 14, 1, "s: Giu");
    mvwprintw(this->hudwin, 15, 1, "q: Esci");

    wrefresh(this->hudwin);

}
void Hud::destroyHUD()
{
    this->punteggio=0;
    wclear(this->hudwin);
    wclear(this->shapeWin);
    wrefresh(this->hudwin);
    wrefresh(this->shapeWin);


}

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
