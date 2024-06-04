#include <fstream>
#include <ncurses.h>

struct Punteggio{
    std::string p;
    int posX;
    int posY;
    Punteggio* next; 
};

class Classifica{
protected:
    WINDOW* win;
    //int numPunteggi=10; voglio stampare solo i primi  10 punteggi più alti
    Punteggio* testa; //puntatore alla testa della lista di punteggi
public:
   
    Classifica();
    Classifica(WINDOW* win);
   
    int Mostra(); //ritorna valore per uscire da schermata classifica

    //funzioni ausiliarie per l'aggiornamento della classifica VANNO TENUTE COME METODI O MEGLIO LIBRERIA?
    Punteggio* fromFileToList(Punteggio* head); //necessaria per aggiornare la classifica
    Punteggio* sortInsert(int points, Punteggio* head); //inserimento del punteggio in una lista ordinata
    void Aggiorna(int points); //aggiorna file di testo con il nuovo punteggio
};
