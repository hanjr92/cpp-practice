#include<iostream>

using String = std :: string;

class Entity
{
    private:
    int x = 0;
    int y = 0;
    public:
    Entity(int x, int y) //python中的self 与this类似，指向类实例
    {
        this->x = x;///this 是Entity* 
        this->y = y;
    }

    int getX() const
    {
        return this->x; ///this 此时是const Entity* 
    }
};



int main()
{
    std::cin.get();
}