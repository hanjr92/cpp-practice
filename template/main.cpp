#include<iostream>


template<typename T,  int N> //模板参数列表，模板参数列表中的模板参数必须是类型，不能是常量，不能是引用，不能是指针，不能是数组，不能是函数，不能是模板参数列表
//模板只会在调用的时候生成真实的类型，而不会在编译的时候生成真实的类型
class MyArray {
    private:
        T data[N];
        int m_size;
    public:
        MyArray() {
            m_size = N;
        }
        void set(int index, T value) {
            data[index] = value;
        }
        T get(int index) {
            return data[index];
        }
        int size() {
            return m_size;
        }
};


int main() {
    MyArray<int, 5> array;
    array.set(0, 1);
    array.set(1, 2);
    array.set(2, 3);
    array.set(3, 4);
    array.set(4, 5);
    std::cout << array.get(0) << std::endl;
    std::cout << array.get(1) << std::endl;
    std::cout << array.get(2) << std::endl;
    std::cout << array.get(3) << std::endl;
    std::cout << array.get(4) << std::endl;
    std::cout << array.size() << std::endl;
    return 0;
}