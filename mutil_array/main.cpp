#include<iostream>


int main()
{
    int** array2d = new int*[50]; //二维数组，开辟50个空间，保存int型指针
    for(int i = 0; i < 50; i++)
        array2d[i] = new int[50];
    
    int*** array3d = new int**[50];//三维数组，开辟50个空间，保存指向int型指针的指针
    for(int i= 0; i < 50; i++)
    {
        array3d[i] = new int*[50];
        for(int j=0; j<50; j++)
        {
            array3d[i][j] = new int[50];
        }
    }
    // 以上初始化多维矩阵的方式 使用了new在heap上开辟空间，在使用过后需要手动释放空间。
    // 但是不能直接使用delete [] 的方式，会导致存储的指针指向的地址未释放造成内存泄漏
    // 2d 数据释放内存需要按照循环从内层释放

        for (int i = 0; i < 50; i++)
            delete[] array2d[i];
        delete[] array2d;
    
    // 多维数组通常会造成内存碎片的问题，不同维度之间new 申请内存时因为heap会将空闲链表内存分配给不同的一维数组
    // 所以不同一维数组间地址不连续，访问时可能 cache miss，造成访问缓慢的问题
    // 在大多数情况下，通常使用一维数组模拟多维数组
    int* array = new int[5*5];
    for(int x=0; x<5; x++)
    {
        for(int y=0; y<5; y++)
        {
            array[x * 5 + y] = 0; // 利用偏移量来虚拟 多维。
        }
    }


}