#include<iostream>
#include<string>

void Printname(std::string& name) //仅接受左值输入
{
    std::cout << "[lvalue] " << name << std::endl;
}

void Printname(const std::string& name)  // const 引用可以接受左值和右值的输入，
//const 本质上是将 右值赋值给 temp的变量，然后将左值temp传入
{
    std::cout << "[lvalue] or [rvalue] " << name << std::endl;
}


void Printname(std::string&& name) //仅接受右值输入
{
    std::cout << "[rvalue] " << name << std::endl;
}


int main()
{
    std::string firstname = "Han";
    std::string lastname = "Jiarong";

    std::string fullname = firstname + lastname;

    Printname(fullname); //简单的可以将左右值以是否绑定可访问的地址来区分。

    Printname(firstname + lastname);

    std::cin.get();

}