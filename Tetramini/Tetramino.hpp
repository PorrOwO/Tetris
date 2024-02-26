class Tetramino
{
private:
    /* data */
    int map[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}; //ogni tetramino è mappato da un vettore 4x4 

public:
    Tetramino(int type); //tyoe indica che tipo di tetramino è eg 1 tetramino linea retta, 2 il quadrato etc
    ~Tetramino();
    void testPrint();
};

Tetramino::Tetramino(int type)
{
    switch (type)
    {
    case 1:
        map[3][0] = 1;
        map[3][1] = 1;
        map[3][2] = 1;
        map[3][3] = 1;
        break;
    case 2:
        map[2][2] = 1;
        map[3][1] = 1;
        map[3][2] = 1;
        map[3][3] = 1;
        break;
    case 3:
        map[3][2] = 1;
        map[3][3] = 1;
        map[2][2] = 1;
        map[2][3] = 1;
        break;
    case 4:
        map[3][1] = 1;
        map[3][2] = 1;
        map[3][3] = 1;
        map[2][3] = 1;
        break;
    
    default:
        break;
    }
}

Tetramino::~Tetramino()
{
}
