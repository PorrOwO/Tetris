#include <iostream>
#include <fstream>
using namespace std;
class hud
{
private:
    string username;
    int punteggio;
public:
    hud(string, int );
    ~hud();
    void draw();
};

hud::hud(string usr, int punt)
{
    this->username = usr;
    this->punteggio = punt;
}

hud::~hud()
{
}

void draw(){}
