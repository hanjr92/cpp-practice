#include<iostream>

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
    (*c)++; // 
    std::cout<< *b << std::endl;
    std::cin.get();
}