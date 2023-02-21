#include<iostream>

class base
{

    public:
        base(){ std::cout << "base constructor\n";}
        virtual ~base(){ std::cout << "base deconstructor\n";}

};

class childbase : public base
{
        public:
        childbase(){ std::cout << "childbase constructor\n";}
        ~childbase(){ std::cout << "childbase deconstructor\n";}
};



int main()
{
    base* a = new base();
    delete a;
    std::cout << "===========================\n";
    childbase* b = new childbase();
    delete b;
    std::cout << "===========================\n";
    base* c = new childbase(); //当基类没有声明虚析构函数时，由于指针指向基类，但是初始化构造函数能够触发派生类，最终销毁时没有正确触发派生类的析构函数。
    delete c; //虚析构函数让编译器意识到析构函数在派生类中也存在，需要按照构造的层级逐级析构，而虚构造函数则是覆盖基类函数。
    std::cout << "===========================\n";
    std::cin.get();
}