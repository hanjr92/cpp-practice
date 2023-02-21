#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

int main()
{
    std::vector<int> values = {2,3,5,1,2,4};
    std::sort(values.begin(), values.end(), std::greater<int>());

    std::sort(values.begin(), values.end(), [](int a, int b)
    {
        if (a==1)
            return false;
        if (b==1)
            return true;
        return a > b;
    }); //自定义排序规则，（int a， int b） 返回true a排在前面， 自定义排序规则可以给对象排序。

    for (int value:values){
        std::cout<< value << std::endl;
    }

    std::cin.get();

}