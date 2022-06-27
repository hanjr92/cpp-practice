#include<iostream>

static void log(const char* message)
{
    std::cout << message << std::endl;
}

// 为了避免重复定义，在头文件中可以使用static 或者 inline 来对函数进行定义：
// inline void log(const char* message)
// {
//     std::cout << message << std::endl;
// }