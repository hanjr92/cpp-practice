#include<iostream>
#include<thread>

static bool s_Finished = false;

void Dowork()
{
    using namespace std::literals::chrono_literals;

    std::cout << "started thread id = " << std::this_thread::get_id() << std::endl;

    while(!s_Finished)
    {
        std::cout <<  "working...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main()
{
    std::thread worker(Dowork);  //执行线程

    std::cin.get();
    s_Finished = true;

    worker.join();  //线程等待 在 thread worker执行结束之前 其他线程不执行 包括主线程
    std::cout << "Finished." << std::endl;
    std::cout << "started thread id = " << std::this_thread::get_id() << std::endl; // 前后两次线程id不同 代表线程不一样
    std::cin.get();

}