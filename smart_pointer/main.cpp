#include<iostream>
#include<memory>//智能指针头文件，一旦一个对象使用智能指针管理后，就不该再使用原始裸指针去操作；

class Entity
{   
    public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }
};


int main()
{   

    {
        std::unique_ptr<Entity> entity(new Entity());// unique_ptr 在构造函数中使用了explicit，确保使用显式调用
        std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();
        // std::unique_ptr<Entity> entity2 = entity;// unique_ptr 禁止了复制构造，保证唯一性
    }//作用域，离开作用域栈上创建的对象将会自动释放，运行可以发现此处调用了两次析构函数


    {
        std::shared_ptr<Entity> entity2; //shared_ptr拥有引用自动计数功能，当引用计数为0将会释放内存
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            std::cout << sharedEntity.use_count() << std::endl;
            entity2 = sharedEntity;
            std::cout << sharedEntity.use_count() << std::endl;
            entity2.reset();//会重置entity2, sharedEntity引用减一
            std::cout << sharedEntity.use_count() << std::endl;
            {
                std::shared_ptr<Entity> entity3 = sharedEntity;
                std::cout << sharedEntity.use_count() << std::endl;
            }
            std::cout << sharedEntity.use_count() << std::endl;//entity3的离开作用域自动析构，sharedEntity引用计数减一
            std::weak_ptr<Entity> weakEntity = sharedEntity; //此时并不会增加sharedEntity的引用计数，weak_ptr主要用来避免循环引用时出现的不正确引用计数；
            //weak_ptr也会随着作用域释放
            std::cout << sharedEntity.use_count() << std::endl;//可以看到并没有增加引用计数。
        }

    }

    std::cin.get();
}