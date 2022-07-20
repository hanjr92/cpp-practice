#include<iostream>


// enum num:int
// {
//     a = 5,b=7,c  // enum默认从0开始依次排序枚举，但如果对一个变量重新赋值，后续变量枚举也会随之变化递增。
// };

enum num:char
{
    a = 5,b=34,c  // c = 35代表的ascii码
    
};
int main()
{   
    num n = c;
    std::cout<<n<<std::endl;
    std::cin.get();
}