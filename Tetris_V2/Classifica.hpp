#include <fstream>
#include <ncurses.h>

struct Punteggio{
    std::string p;
    Punteggio* next; 
};

class Classifica{
protected:
    WINDOW* win;
    Punteggio* testa; //puntatore alla testa della lista di punteggi
public:
   
    Classifica();
    Classifica(WINDOW* win);
   
    int Mostra(); //ritorna valore per uscire da schermata classifica
    Punteggio* fromFileToList(Punteggio* head); //necessaria per aggiornare la classifica
    Punteggio* sortInsert(int points, Punteggio* head); //inserimento del punteggio in una lista ordinata
    void Aggiorna(int points); //aggiorna file di testo con il nuovo punteggio
};
