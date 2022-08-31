#include<iostream>

#include<array>
#include<functional>
#include<utility>

void SpeedNow1(int dx, int dy, int& x, int& y) // 使用引用传递，将要返回的引用作为参数传入
{
    x += dx;
    y += dy; 
}

void SpeedNow2(int dx, int dy, int* x, int* y) // 使用指针传递，将要返回的地址作为参数传入
{
    if(x) // 由于使用指针，因此需要判断指针是否非空，使用指针作为返回值有一个额外的功能就是 可以传入nullptr，此时可以无返回，而引用则必定非空。
        *x += dx;
    if(y)
        *y += dy; 
}


std::array<int, 2> SpeedNow3(int dx, int dy) // 使用数组作为返回值 与vector使用类似， array创建在栈上，vector创建在堆上， 列表内只能返回相同类型的数值
{

}

std::tuple<int, int>SpeedNow4(int dx, int dy)  //使用tuple可以返回不同类型的数值
{
    std::make_tuple<int, int>;//但是使用tuple作为返回值时，使用 std::get<idx>(tuple)无法获取变量名称，对于程序来说缺乏可读性
}


struct Speed
{
    int x;
    int y;
};

Speed SpeedNow5(int dx, int dy)  //使用struct可以返回不同类型的数值,并且使用返回值的时候直接可以取struct内的变量名称作为属性使用，程序可读性较高。
{
    return {dx, dy};
}


int main()
{
    int x =0;
    int y =0;
    SpeedNow1(2, 3, x, y); 
    std::cout << x << ',' << y<< std::endl;
    SpeedNow2(4, 5, &x, &y); 
    std::cout << x << ',' << y<< std::endl;

    std::cin.get();
}