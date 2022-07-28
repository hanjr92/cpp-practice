#include<iostream>
#include<array>
#include<vector>

class Entity
{
    private:
        static const int ArraySize = 10; //const修饰的变量可以在运行时才初始化，而constexpr则一定会在编译期初始化。const表示的是read only的语义，保证修饰的变量运行时不可以更改。
        std::array<int, ArraySize> m_array;
        int n_array[ArraySize]; //数组的初始化方式，必须指定长度
        int* v_array = new int[ArraySize];
        std::vector<int> l_array = std::vector<int>(ArraySize); 
    public:
        Entity(){
        
        for(int i = 0; i < ArraySize; i++)
        {
            m_array[i] = i;
            n_array[i] = i;
            v_array[i] = i;
            l_array[i] = i;
        }
        }
        
};

int main()
{
    Entity e;
    return 0;
}