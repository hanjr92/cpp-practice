#include<iostream>

using String = std :: string;

class Entity
{
    public:
    int x = 0;
    int y = 0;
    Entity(int dx, int dy) : x(dx), y(dy) {}

    Entity add(Entity other)
    {
        return Entity(x + other.x, y + other.y);
    }
    Entity operator+(Entity other)
    {
        // return add(other);
        return Entity(x + other.x, y + other.y);
    }

    Entity mutiply(Entity other)
    {
        return Entity(x * other.x, y * other.y);
    }

    Entity operator*(Entity other)
    {
        // return mutiply(other);
        return Entity(x * other.x, y * other.y);
    }


    Entity sub(Entity other)
    {
        return Entity(x - other.x, y - other.y);
    }

    Entity operator-(const Entity& other) const
    {
        // return sub(other);
        return Entity(x - other.x, y - other.y);
    }

    bool operator==(const Entity& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Entity& other) const
    {
        return !(*this == other);
    }

};

std::ostream& operator<<(std::ostream& os, Entity& other)
{
    os << "(" << other.x << ", " << other.y << ")";
    return os;
}

int main()
{
    Entity a(1, 2);
    Entity b(3, 4);
    Entity c(0.5, 0.5);
    Entity d = a.add(b);
    Entity e = a.sub(b);
    Entity f = a.mutiply(b);
    Entity g = a + b*c - d;
    std::cout << g << std::endl;
    if (a==b)
    {
        std::cout << "a == b" << std::endl;
    }

    if (a!=b)
    {
        std::cout << "a != b" << std::endl;
    }
    std::cin.get();


}