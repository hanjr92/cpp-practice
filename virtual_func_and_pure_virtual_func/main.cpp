#include<iostream>


class Base{
public:
    virtual void print() = 0; // pure virtual function 纯虚函数，在cpp中被当作接口使用，表明该方法必须在子类中实现。
};



class Entity
{
    public:
        void PrintName()
        {
            std::cout << "Entity" << std::endl; //未加virtual修饰的基类函数不能被重写，所有子类的方法都将指向基类的方法
        }
};

class Entity1
{
    public:
        virtual void PrintName()
        {
            std::cout << "Entity1" << std::endl; // virtual 修饰的虚函数可以在子类中被重写，实例化的子类方法将自动指向子类的方法。
        }

};

class Player : public Entity
{   private:
        std::string Name;

    public:
        Player(std::string name)
        {
            Name = name;
        }
        void PrintName()
        {
            std::cout << Name << std::endl;
        }
};

class Player1 : public Entity1
{   private:
        std::string Name;

    public:
        Player1(std::string name)
        {
            Name = name;
        }
        void PrintName() override  // override 表明该方法被重载
        {
            std::cout << Name << std::endl;

        }
};

void Print(Entity* entity)
{   
    entity->PrintName();
}

void Print1(Entity1* entity)
{
    entity->PrintName();
}

int main()
{
    Entity* entity = new Entity();
    Player* player = new Player("Player");
    Print(entity);
    Print(player);

    Entity1* entity1 = new Entity1();
    Player1* player1 = new Player1("Player1");
    Print1(entity1);
    Print1(player1);
    std::cin.get();

}