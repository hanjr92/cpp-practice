#include<iostream>


class Entity{

    private:
    mutable int x = 0; // mutable 表示该变量可以在const修饰的函数中被修改
    int y = 0;
    public:
    void setX(int dx ) const
    {
        x = dx;
    }
    void setY(int dy ) const//声明成员函数时，末尾加const修饰，表示在成员函数内不得改变该对象的任何数据。这种模式常被用来表示对象数据只读的访问模式。
    {
        y = dy;
    }
};

int main()
{
    const int a = 8;
    int temp = 7;
    // a = 6; // 由于被const修饰，此时a属于常量，不能对a进行修改。
    const int* b = &a; //
    // (*b)++; 
    b++;// b是常量指针，指针指向的内存内数据不可变，但指针指向的内存地址可变

    int *const c = &temp;
    // c++;
    (*c)++; // c是指针常量，指针指向的内存地址不可变，但指针指向的内存内数据可变
    
    int i = 10;
    int j = 100;
    const int &r = i;
    int const &s = j;
    // r = j; // 由于r是常量引用，不能对r进行修改
    Entity e;
    e.setX(10);
    e.setY(10);
    std::cin.get();
}