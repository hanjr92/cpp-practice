#include<iostream>


void add(int x, int y)
{
    std::cout<< "the sum is " << x + y << std::endl;
}

void mul(double x, double y)
{
    std::cout<< "the res is" << x * y << std::endl;
}


template <typename T>
bool ascending(T x, T y)
{
    return x > y;
}

template <typename T>
bool descending(T x, T y)
{
    return x < y;
}


template<typename T>
void bubblesort(T *a, int n, bool(*cmpfunc)(T x, T y)){
    bool sorted = false;
    while(!sorted){
        sorted = true;
        for (int i=0; i<n-1; i++)
            if (cmpfunc(a[i], a[i+1])) {
                std::swap(a[i], a[i+1]);
                sorted = false;
            }
        n--;
    }
}

int main()
{
    int a = 3;
    int b = 4;
    double c = 4.5;
    double d = 5.4;

    // auto addfunc = add;
    void (*addfunc)(int x, int y) = add; //不用自动推断的显式写法
    auto mulfunc = mul;
    addfunc(a, b);

    int array[8] = {5, 6, 2, 14, 35, 21, 11, 25};
    bubblesort<int>(array, 8, ascending);

    for (auto e:array) std::cout << e << " ";
    std::cout << std::endl;

    bubblesort<int>(array, 8, descending);

    for (auto e:array) std::cout << e << " ";
    std::cin.get();
}