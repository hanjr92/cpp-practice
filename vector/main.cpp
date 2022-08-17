#include<iostream>
#include<vector>

struct Vertex
{
    float x, y, z;

    Vertex(float dx, float dy, float dz) 
    : x(dx), y(dy), z(dz)
    {
        std::cout<<"construct"<<std::endl;
    }

    Vertex(const Vertex& other)
    :x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copied" << std::endl;
    }
};


std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << "," << vertex.y << "," << vertex.z;
    return stream;
}

int main()
{
    std::vector<Vertex> vertices;
    vertices.reserve(9); //合理的预估vector的容量大小，如果设置较小，扩容时会复制当前元素到新的vector内，再销毁原始元素。
    vertices.push_back({1,2,3}); //push_back会调用构造函数先生成一个struct，然后再复制到vector末端，因此会触发copy构造
    vertices.push_back({4,5,6});
    vertices.push_back({7,8,9});
    std::cout << "=================================" << std::endl;
    vertices.emplace_back(Vertex(1,2,3));//如果emplace_back一个实例，也会先构造后复制触发copy构造函数
    vertices.emplace_back(Vertex(1,2,3));
    vertices.emplace_back(Vertex(1,2,3));
    std::cout << "=================================" << std::endl;
    vertices.emplace_back(1,2,3);//emplace_back可以直接传入实参，在vector末端直接构造，而不用触发copy构造
    vertices.emplace_back(1,2,3);
    vertices.emplace_back(1,2,3);


    std::cout << "=================================" << std::endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << std::endl;
    }
    
    std::cout << "=================================" << std::endl;
    for (const Vertex& v : vertices) // 使用引用传递避免复制Vertex
    {
        std::cout << v << std::endl;
    }

    // vertices.clear(); //清楚vector
    vertices.erase(vertices.begin() + 1);//使用迭代器删除指定vector内元素
    std::cout << "=================================" << std::endl;
    for (const Vertex& v : vertices) // 使用引用传递避免复制Vertex
    {
        std::cout << v << std::endl;
    }
    std::cin.get();

}