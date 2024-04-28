#include "../includeManager.hpp"
/* TO DO
 * aggiungere a punteggio un metodo che inizializzi le varie posizioni dei punteggi (come opzioni)
 */
//è meglio farlo struct??
class Punteggio{
public: //fare in modo che siano protected
    string p;
    int posX;
    int posY;
    Punteggio* next; //ogni punteggio punta a quello successivo
public:
    void setPosition(int x, int y);
};

class Classifica{
protected:
    Window win;
    //int numPunteggi=10; voglio stampare solo i primi  10 punteggi più alti
    Punteggio* testa; //puntatore alla testa della lista di punteggi
public:
    // WINDOW* winC;
    Classifica();
    Classifica(Window win);
    void setPointsPosition(); //NON VA
    int Mostra(); //ritorna valore per uscire da schermata classifica

    //funzioni ausiliarie per l'aggiornamento della classifica VANNO TENUTE COME METODI O MEGLIO LIBRERIA?
    Punteggio* fromFileToList(Punteggio* head); //necessaria per aggiornare la classifica
    Punteggio* sortInsert(int points, Punteggio* head); //inserimento del punteggio in una lista ordinata
    void Aggiorna(int points); //aggiorna file di testo con il nuovo punteggio
};