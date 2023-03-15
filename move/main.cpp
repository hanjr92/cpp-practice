#include<iostream>
#include<string.h>

class String
{
    public:
        String() = default; //C++11 新标准中，可以通过 =default 关键来声明构造函数，告诉编译器为该类生成一个默认的版本
        String(const char* string)
        {   
            printf("Created!\n");
            size = strlen(string);
            data = new char[size];
            memcpy(data, string, size);
        }

        String(const String& other)
        {   
            printf("Copied!\n");
            size = other.size;
            data = new char[size];
            memcpy(data, other.data, size);
        }

        String(String&& other) noexcept //移动语义 移交数据地址
        {   
            printf("Moved!\n");
            size = other.size;
            data = other.data;

            other.size = 0;
            other.data = nullptr;
        }

        void Print()
        {
            for(uint32_t i = 0; i < size; i++)
            {
                printf("%c", data[i]);
            }
            printf("\n");
        }

        ~String()
        {
            printf("destoried!\n");
            delete[] data;
        }

    private:
        char* data;
        uint32_t size;
};

class Entity
{
    public:
        Entity() = default;
        Entity(const String& name):Name(name)
        {

        }

        Entity(String&& name):Name(std::move(name)) // (String&&) 强制将入参转化为右值，可以使用更加通用 std::move 自动识别数据类型
        {

        }

        void PrintName()
        {
            Name.Print();
        }
    private:
        String Name;
};

int main()
{
    Entity entity(String("hello")); // 先触发构造函数，然后再触发复制拷贝，会有额外的内存申请开销

    Entity entity1("hello"); // 提供移动赋值可以避免数据的拷贝，而只是把入参当作临时的右值，将指针转移，相当于 entity1 接管 传入的Stirng

    std::cin.get();



}