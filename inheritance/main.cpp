#include<iostream>

class Entity
{
    public:
    int x = 0;
    int y = 0;

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }

};
//公有继承：当一个类派生自public基类时，基类的public成员也是派生类的public成员，基类protected成员也是派生类的protected成员，基类的private成员不能直接被派生类访问，但是可以通过基类的public和protected成员来访问。
//保护继承：当一个类派生自protected的基类时，基类的public和protected成员将成为派生类的protected成员
//私有继承：当一个类派生自private的基类时，基类的public和protected成员将成为派生类的private成员
class Player : public Entity //class <派生类名> : <继承方式(public/protected/private)> <基类名>
//派生类可以访问基类中的所有非私有成员。因此基类成员如果不想被派生类的成员函数访问，则应将基类成员声明为private。
//派生类可以继承所有基类的方法，但下列情况除外：
//基类的构造函数，析构函数和拷贝构造函数
//基类的重载运算符
//基类的友元函数
{
    public:
        const char* Name;
    
    void printname()
    {
        std::cout << Name << std::endl;
    }

};

int main()
{
    std::cout<< sizeof(Entity)<<std::endl;  // size = 8
    std::cout<< sizeof(Player)<<std::endl; // size = 16， 继承之后，player就是entity类的超集，player包含了entity所有的数据。
    Player player;
    player.move(1,2);
    char name = 'A';
    player.Name = &name;
    player.printname();
    std::cin.get();

}