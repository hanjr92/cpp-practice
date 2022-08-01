#include<iostream>
#include<string>

int main()
{   
    char l[6] = {'a','b',0,'d','e', 0}; //0 is a null character 代表空字符休止符
    std::cout << l << std::endl;
    char name1[] = "hello"; // 编译器在栈上创建一个字符串，把"hello"从常量区复制到寄存器，修改name1【0】就相当于修改数组元素一样，是可以的。
    name1[0] = 'H';
    std::cout << name1 << std::endl;
    const char* name = u8"hello";// name是一个指针，直接指向常量区，修改name就是修改常量区的内容，这是不允许的。
    // char 就是 utf8编码，指使用8位的字符编码，一个字符占用1个字节
    const wchar_t* name2 = L"hello"; //wchar_t是宽字符，一般指2个字节表示字符，但是会因为编译器不同而变化
    const char16_t* name3 = u"hello";//char16_t 是一个2字节的字符，是utf16编码，一个字符占用2个字节。
    const char32_t* name4 = U"hello";//char32_t 是一个4字节的字符，是utf32编码，一个字符占用4个字节。

    
    std::cout << name << std::endl;

    // std::string s = "hello";
    // std::wstring s1 = L"hello";
    // std::u16string s2 = u"hello";
    // std::u32string s3 = U"hello"; //与char类似
    std::cin.get();
    return 0;
}