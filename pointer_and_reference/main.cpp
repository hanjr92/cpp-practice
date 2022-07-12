#include<iostream>
#include<string.h>


void increase_by_pointer(int* var){
    (*var)++;
}

void increase_by_reference(int& var){
    var++;
}

void pointer(){
    int var = 8;
    int* pointer = &var;              //在stack 上面 创建地址
    std::cout<< pointer << std::endl; //指针本质是指向内存的地址，因此打印指针会打印目前的内存地址
    std::cout<< &pointer <<std::endl; //指针本身也要保存在内存中，因此取地址符& ，会获取当前指针的地址。 
    std::cout<< *pointer <<std::endl; //*符号是为了解引用，获取指针指向的地址。


    char* buffer = new char[8];
    memset(buffer, 0, 8); // create data on heap, accept (pointer, data, size)
    // std::cout<< buffer <<std::endl;
    std::cout<< &buffer <<std::endl;
    // std::cout<< *buffer << std::endl;
    char** ptr = &buffer;// pointer is a var too. So  double pointer can point to pointer. 

    std::cout<< &ptr <<std::endl;

    delete[] buffer; // delete data from heap
}

void reference()
{
    int var = 5;
    int* ref = &var; // reference is not a really variable. It doesn't exist, just exist in code. Compliers do not create "ref".
    increase_by_pointer(ref); // pass by pointer. 
    std::cout<< var <<std::endl;
    increase_by_reference(var); // pass by reference. pointer maybe a nullptr, but reference would not be a NULL forever. Use pass by reference!!!!!
    std::cout<< var <<std::endl;
}

int main(){
    pointer();
    reference();
    std::cin.get();
    return 0; 
}

