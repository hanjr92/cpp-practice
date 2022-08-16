#include<iostream>
#include<cstring>

class String
{
    public:
        char* m_buf;
        unsigned int m_size;
    // public:
        String(const char* string)
        {
            m_size = strlen(string);
            m_buf = new char[m_size];//
            memcpy(m_buf, string, m_size);
            m_buf[m_size] = 0;
        }

        ~String()
        {
            delete[] m_buf;
        }

        // String(const String& other)
        // : m_buf(other.m_buf), m_size(other.m_size)
        // {

        // } // 默认copy构造函数

        // String(const String& other) = delete; // unique_ptr 中禁止copy构造的方式

        String(const String& other) : m_size(other.m_size)
        {   
            std::cout << "Copy Constructor!" << std::endl;
            m_buf = new char[m_size + 1];
            memcpy(m_buf, other.m_buf, m_size+1);
        } // deep copy
    
    char& operator[](unsigned int index)
    {
        return m_buf[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
    //友元函数时可以直接访问类的私有成员或保护成员，它是定义在类外的普通函数，它不属于任何类，但需要在类的定义中加以声明。
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_buf;
    return stream;
}

struct Vector
{
    float x;
    float y;
    Vector(int dx, int dy):x(dx), y(dy){}
};

void PrintString1(String string)
{
    std::cout << string << std::endl; //值传递，传递复制，会触发copy构造
}

void PrintString2(const String& string) //引用传递，不会触发copy构造
{
    std::cout << string << std::endl;
}

int main()
{
    Vector a(1.0, 2.0);
    Vector b = a; // 值copy，b和a并不指向同一内存
    b.x = 2.0;//改变b并不改变a
    std::cout << a.x << std::endl;

    Vector* a1 = new Vector(1.0, 2.0);
    Vector*b1 = a1;// b和a指向同一内存
    b1->x = 2.0;//改变b同时改变a
    std::cout << a1->x << std::endl;

    String string = "Hello";
    std::cout << string << std::endl;
    String second = string; //此时copy构造了second，但是当string和second同时析构时，会delete两次m_buf，由于默认的copy构造只会浅copy，简单的将地址赋给新的实例，因此会重复释放造成错误。
    second[1] = 'a';
    std::cout << string << std::endl;//shallow copy 会同时改变string， deep copy 不会改变原string
    PrintString1(string); //会触发copy构造
    PrintString1(second);
    PrintString2(string); //不会触发copy构造
    PrintString2(second);
    std::cin.get();
}