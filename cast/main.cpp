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
    // static_cast, reinterpret_cast, const_cast, dynamic_cast

}