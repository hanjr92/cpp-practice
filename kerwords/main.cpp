#include<iostream>

int main()
{
    const int a = 8;
    int temp = 7;
    // a = 6; // 由于被const修饰，此时a属于常量，不能对a进行修改。
    const int* b = new int; //
    b = &temp;
    b = &a;
    std::cout<< *b << std::endl;
    std::cin.get();
}