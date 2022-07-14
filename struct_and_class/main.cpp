#include<iostream>


struct Player1    // the member of struct is public in default. I would never use inheritance with structs!!!!!!!!!!!!!!!
{
    int x = 0;
    int y = 0;
    int speed = 1;

    void move(int dx, int dy)
    {
        x += dx * speed;
        y += dy * speed;
    }
    void cur()
    {
        std::cout<< "now : " << x <<"," << y << std::endl;
    }
};

class Player  // the member of class is private in default.  
{
    public:
    void move(int dx, int dy)
    {
        x += dx * speed;
        y += dy * speed;
    }

    void cur()
    {
        std::cout<< "now : " << x <<"," << y << std::endl;
    }

    private:
    int x = 0;
    int y = 0;
    int speed = 1;
};

int main()
{   
    Player player;
    player.cur();
    player.move(2,3);
    player.cur();
    std::cin.get();
    return 0;
}

