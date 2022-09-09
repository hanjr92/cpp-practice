#include<iostream>
#include<string>
#include<algorithm>

namespace a{

    void print(const std::string &s)
    {
        std::cout<< s << std::endl;
    }

}

namespace b{

    void print(const std::string &s)
    {
        std::string temp = s;
        std::reverse(temp.begin(), temp.end());
        std::cout<< temp << std::endl;

    }

    inline namespace bb{
        int size(const std::string &s)
        {
            return s.size();
        }
    }
}

int main()
{
    std::string s = "hello!";
    a::print(s);
    b::print(s);
    std::cout << b::bb::size(s) << std::endl;
    std::cout << b::size(s) << std::endl; //inline 使得子命名空间可被父命名空间直接调用
    std::cin.get();
}