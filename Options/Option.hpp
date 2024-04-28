#include <string>

class Option {
protected:
    std::string title;
    int xPos;
    int yPos;
public:
    Option(std::string title);

    std::string getTitle();
    int getX();
    int getY();

    void setX(int val);
    void setY(int val);
};