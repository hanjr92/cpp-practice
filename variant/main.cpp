#include<iostream>
#include<variant>
int main()
{

    std::variant<std::string, int> data; //单一变量 存储多种类型数据，sizeof是所有类型的和
    data = 1;
    std::cout << data.index() << std::endl;  //输出当前data存储的类型索引  1
    data = "hello";
    std::cout << data.index() << std::endl;//输出当前data存储的类型索引  0

    std::cout << std::get<std::string>(data) << std::endl; //获取data中的数据，如果不是指定的类型抛出异常

    auto* ref = std::get_if<int>(&data); //get_if获取指定类型的指针，如果存的不是该类型的数据，返回空指针
    std::cout << ref << std::endl;
}