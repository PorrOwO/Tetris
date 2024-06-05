#include "Classifica.hpp"

Classifica::Classifica()
{
    this->win = newwin(40,40,0,0);
    this->testa=fromFileToList(NULL);
};

Classifica::Classifica(WINDOW* win)
{
    this->win = win;
    this->testa=NULL;
   // this->testa=fromFileToList(NULL);
};


int Classifica:: Mostra() //stampo i punteggi dal file
{  
    this->testa=fromFileToList(NULL);
    int yMax, xMax;
    getmaxyx(this->win, yMax, xMax); 
    int q; 
    std::ifstream input;
    input.open("classifica.txt");
    std::string linea;
    int Y=4;
    int X = xMax;
    //int X=this->win->_maxx;

    box(this->win,0,0);
    while(!input.eof() && Y<yMax-1) 
    {
        getline(input,linea);
        mvwprintw(this->win,Y,X/2-(linea.length())/2-linea.length()%2,"%s",linea.c_str());
        Y++;
    }

    input.close();
    wrefresh(this->win);
    do{
        wattron(this->win, A_STANDOUT);
        mvwprintw(this->win,1,1,"esci");
        wattroff(this->win, A_STANDOUT);
        q=wgetch(this->win);
    } while(q!=10);
   
    wclear(this->win);
    refresh();
    return -1;
};


Punteggio* Classifica:: fromFileToList(Punteggio* head)
{
    std::ifstream input;
    std::string linea;
    input.open("classifica.txt");
    Punteggio* tmp=NULL;
    while(!input.eof())
    {   getline(input, linea); 
        if(linea!="\0")
        {
            if(head==NULL) //inserimento di una linea in una lista vuota
            {
                head=new Punteggio;
                head->p=linea;
                head->next=NULL;
                tmp=head;
            }
            else  //inserimento di una linea in una lista non vuota
        {
                while(tmp->next!=NULL) tmp=tmp->next;

                tmp->next=new Punteggio;
                tmp=tmp->next;
                tmp->p=linea;
                tmp->next=NULL;

            }
        }
    }
    return head;
};


Punteggio* Classifica::sortInsert(int points, Punteggio* head)
{
    if(head==NULL)
    {head= new Punteggio;
        head->p=std::to_string(points);
        head->next=NULL;
        return head;

    }
    else
{
        if(points>=stoi(head->p,0,10) )
        {
            Punteggio* tmp= new Punteggio;
            tmp->next=head;
            tmp->p=std::to_string(points);
            head=tmp;
            return head;
        }
        else 
    {
            head->next=sortInsert(points,head->next);
            return head;
        }
    }
};

void Classifica::Aggiorna(int points)
{ std::ofstream output;
    this->testa=fromFileToList(NULL);
    this->testa=sortInsert(points,testa);
    output.open("classifica.txt");

    while(testa!=NULL)
    { output<<testa->p<<std::endl;
        testa=testa->next;

    }
    output.close();


};
