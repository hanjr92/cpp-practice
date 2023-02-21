#include<iostream>
#include<string.h>

union U
{
    int x;
    float y;
};

union U1
{
    struct node
    {
        int x;
        long long y;
    };
    double z;
}; //也可以union里面放个结构体。里面的结构体是需要满足内存对齐的。


struct short_str
{
    union 
    {
        unsigned long long hs;
        char s[8];
    };
};

struct var{
    union {
        int iv;
        double dv;
        char* sv;
    };
    var(const int& v) :iv{ v } {};
    var(const double& v) :dv{ v } {};
    var(const char* s) {
        int len = strlen(s);
        sv = new char[len + 1];
        memcpy(sv, s, len + 1);
    }
};

int main()
{
    char data[4]; // C/C++ 为我们提供了强制类型转换有个4个字节的数组，然后告诉编译器将这部分内存当作int或者float来看待。
    *(int*)data = 114514;
    std::cout << *(int*)data << std::endl;
    *(float*)data = 1919.810;
    std::cout << *(float*)data << std::endl;

    U u; //union 实际上就是两个变量共用同一块内存。如果是多个变量的话，union的大小就为最大的那一个变量。
    u.x = 114;
    std::cout << u.x << std::endl;
    u.y = 5.14;
    std::cout << u.y << std::endl;

    std::cout << sizeof(U1) << std::endl;
    std::cout << sizeof(U1::node) << std::endl;

    short_str s;
    memcpy(s.s, "hello", 6);//用到了匿名union，就是不给这个union名字，但是还是可以访问到数据
    std::cout << s.s << std::endl;//比如对于长度小于等于8的短字符串,快速获取字符的二进制表示
    std::cout << s.hs << std::endl;
    
    var x = 1415; //利用union我们可以轻易的写出一个简单的动态类型
    std::cout << x.iv << std::endl;
    x = 3.14;
    std::cout << x.dv << std::endl;
    x = "hello world";
    std::cout << x.sv << std::endl;

    std::cin.get();
}