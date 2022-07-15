#include<iostream>

extern int var; //extern 关键词是告诉编译器该对象已经在外部文件定义，可以通过其他文件进行导入。

// extern static 可以修饰变量、函数、类等各种对象。


class CMyclass{
    int n;
    static int s;
};    //则sizeof（CMyclass）等于4


struct Entity
{
    int x, y;

    void print()
    {
        std::cout << x << "," << y << std::endl;
    }
};


struct Entity1
{
    static int x, y;  // 静态成员变量是该类的所有对象所共有的。
    //而静态成员变量一共就一份，无论这个类的对象被定义了多少个，静态成员变量只分配一次内存，由该类的所有对象共享访问。
    // 所以，静态数据成员的值对每个对象都是一样的，它的值可以更新

    void print()  //非静态成员函数可以任意地访问静态成员函数和静态数据成员；
    {
        std::cout << x << "," << y << std::endl;
    }

};

int Entity1::x=0;    //定义并初始化静态数据成员.静态成员变量必须初始化，而且只能在类体外进行!!!!!

struct Entity2
{
    static int x, y; //静态数据成员和普通数据成员一样遵从public,protected,private访问规则；

    static void print()
    {
        std::cout << x << "," << y << std::endl;
    }

};

struct Entity3
{
    int x, y;

    static void print()
    {                                             //静态成员函数与静态成员变量一样，都是类的内部实现，属于类定义的一部分。
        std::cout << x << "," << y << std::endl;  // static methods cannot  access non static.
        // 普通成员函数必须具体作用于某个对象，而静态成员函数并不具体作用于某个对象。
        // 普通的成员函数一般都隐含了一个this指针，this指针指向类的实例本身，
        // 静态成员函数属于类本身，而不作用于对象，因此它不具有this指针。
        // 正因为它没有指向某一个对象，所以它无法访问属于类对象的非静态成员变量和非静态成员函数，它只能调用其余的静态成员函数和静态成员变量。
        //！！！静态成员之间可以相互访问，即静态成员函数（仅）可以访问静态成员变量、静态成员函数；
    }

};


void fn()
{
	static int n=10; // 静态局部变量保存在全局数据区，而不是保存在栈中，每次的值保持到下一次调用，直到下次赋新值。
	std::cout<<n<<std::endl;
	n++;
}

int main()
{
    Entity e;
    e.x = 2;
    e.y = 3;
    e.print();

    std::cin.get();
    return 0;
}