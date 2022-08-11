#include<iostream>

using String = std :: string;

class Entity
{
    public:
        String Name;
        int Age;
        explicit Entity(int age):Age(age){} //explicit 可以禁用构造函数的隐式转换
        Entity(const String& s) :  Name{s}{}
};

void Print(const Entity& e)
{
    std::cout<<e.Name<<","<<e.Age<<std::endl;
}

int main()
{
    Print(1); //由于explicit的修饰，现在必须显式的实例化
    Print(Entity(1));
    Print(String("hello"));//隐式转换，可以调用对应类型的构造函数，而不不用显示的实例化
    Entity a = String("hello");
    std::cin.get();
}