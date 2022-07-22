#include<iostream>

// RAII是Resource Acquisition Is Initialization
// 正确使用构造和析构函数，可以正确的申请资源、销毁资源，避免资源泄露，包括不限于申请内存、网络连接、互斥锁以及文件I/O开关等

class Person
{
private:
    float Height;
    int Age; 
    int *array;

public:
    Person(int age, float height) // 构造函数，用来初始化类，可以在构造函数中通过new 在heap中创建数据。
    {
        array = new int [8];
        Age = age;
        Height = height;
    }

    ~Person() //析构函数 Destructor，用于销毁实例，如果在构造函数中有手动创建在heap上的数据，需要在析构函数中delete
    {
        if(array != nullptr)
        {
            std::cout<<"Delete Array!"<<std::endl;
            delete[] array;
            array = nullptr;
        }
        std::cout<< "Destroyed Person!" << std::endl;
    }

    void print()
    {
        std::cout<<"age : "<<Age<<","<<"height: "<<Height<<std::endl;
    }

};

void func()
{
    Person person(2, 34.2);
    person.print();
}


int main()
{
    func(); //通过函数类实例化，可以看出当函数作用域结束时，会自动触发类的析构函数。
    Person person(10, 145.2);
    person.print();
    std::cin.get();  //如果在主函数中实例化类，只有当退出主程序时，实例化类才会被销毁。 因为类实例化在栈上，此时的作用域时整个mian函数。
    return 0; 

}