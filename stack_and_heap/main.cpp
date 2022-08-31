#include<iostream>

struct Vector1
{
    float x, y, z;

    Vector1():x(10), y(11), z(11) {}
};

int main()
{   
    {
        int value = 0;
        int array[5];
        array[0] = 1;
        array[1] = 2;
        array[2] = 3;
        array[3] = 4;
        array[4] = 5;
        Vector1 vector;
    }// 以上数据创建在stack上，地址连续，并且时间域跟随作用域，离开作用域后，栈上数据会自动销毁

    
    int* hvalue = new int;
    *hvalue = 5;
    int* harray = new int[5];
    harray[0] = 1;
    harray[1] = 2;
    harray[2] = 3;
    harray[3] = 4;
    harray[4] = 5;
    Vector1 *hvector = new Vector1();
    // 以上数据创建在heap上,heap上的数据需要手动销毁，heap维护一个空闲内存列表，每次创建数据会首先查询空闲内存，然后分配空闲内存创建数据，因此创建数据会比栈慢。
    //其次由于调用heap数据可能存在cache miss的问题，导致调用时间变长。栈的数据连续，调用活跃 cache miss的问题会相对更少。

    delete hvalue;
    delete[] harray;
    delete hvector; //释放heap内存，更新空闲内存
    std::cin.get();

}