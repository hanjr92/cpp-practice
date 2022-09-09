#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void ForEach(std::vector<int>& values, const std::function<void(int)>& func)
{
    for(int value : values)
    {
        func(value);
    }
}


int main()
{
    std::vector<int> a = {1,3,2,3,4,57,4,55,66};
    auto lambda = [](int a){std::cout<< a << std::endl;};
    ForEach(a, lambda);
    std::sort(a.begin(), a.end(), [](int a, int b){return a < b;});
    ForEach(a, lambda);

    int x = 5;
    int y = 6;
    auto func = [x](){std::cout << x << std::endl;}; // lambda 中的[]可以捕获作用域内的变量，[x]则仅仅按值捕获变量x
    func();
    auto func1 = [=](){std::cout << x << ',' << y << std::endl;}; //[=]指定可以按值捕获作用域内的任何变量，值捕获不可以在函数体内对变量进行修改
    func1();

    auto func2 = [&x](){std::cout << ++x << std::endl;}; //可以使用引用捕获调用lambda表达式,引用捕获x， 使用[&]可以引用捕获作用域内的所有变量
    func2();
    std::cout<<"the original x is " << x <<std::endl; //引用则修改原始变量

    //需要对某个变量进行修改，或者说局部范围内的修改，当退出该作用域的时候，变量又恢复原值。
    //对于按值捕获的变量，编译器会将其设置为只读(read only)，所以对只读变量进行尝试修改的操作是不被编译器所允许的，而mutable 则可以解决此类错误
    auto func3 = [x]()mutable{std::cout << ++x << std::endl;};
    func3();
    std::cout<<"the original x is " << x <<std::endl;

    std::cin.get();

}