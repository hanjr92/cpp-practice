// #pragma once   //防止头文件被重复导入到同一个cpp文件内，造成重复定义的错误。
// 第二种防止头文件被重复载入的方法是 使用#ifndef #deifne #endif
#ifndef _LOG_H
#define _LOG_H
#include<iostream>

inline void log(const char* message)
{
    std::cout << message << std::endl;
}

#endif



// #include<iostream>

// static void log(const char* message)
// {
//     std::cout << message << std::endl;
// }

// 为了避免重复定义，在头文件中可以使用static 或者 inline 来对函数进行定义：
// inline void log(const char* message)
// {
//     std::cout << message << std::endl;
// }