#include<iostream>

using String = std :: string;

class Entity
{
    private:
        String Name;
    
    public:
        Entity():Name("UnKnow"){} // 初始化列表
        Entity(const String& s) :  Name{s}{}

    const String& GetName() const {return Name;}
        ~Entity(){
            std::cout << "delete Entity" << std::endl;
        }
};

void func(Entity* &entity) // 对引用操作就是对原变量操作。因此对指针变量本身的修改无法作用到原指针变量，所以需要通过引用来实现修改指针变量。
{
    Entity e = Entity("hello");
    entity = &e;
} //函数中的代码创建在栈帧中，随着函数作用域的消失，函数内创建的数据将会被销毁。

int main()
{
    Entity* e;
    func(e);
    std::cout << e->GetName()<< std::endl;
    {
        Entity entity("hello");  //在栈中创建
        e = &entity;
        std::cout << e->GetName() << std::endl;
    }
    std::cout << e->GetName()<< std::endl;

    {
        Entity* entity = new Entity("hello"); //在堆中创建，需要手动释放占用的堆内存
        e = entity;
    }
    std::cout << e->GetName() << std::endl;
    delete e; //释放通过new占用的内存

    int* arr = new int[50]; //分配数组内存
    delete[]  arr;// 释放数组内存
    std::cin.get();
}