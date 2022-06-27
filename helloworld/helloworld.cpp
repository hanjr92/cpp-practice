#include<iostream> //使用<>导入的是设置中的include默认地址
#include "log.h" //使用""导入的是cpp工程中的相对地址

// void log(const char* message);

int main(){
    log("hello world!");
    std::cin.get();
}


