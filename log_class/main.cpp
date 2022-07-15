#include<iostream>


class LOG
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

private:
    int LogLevel = 0;

public:
    void SetLevel(int level)
    {
        LogLevel = level;
    }
    void Info(const char* message)
    {   
        if(LogLevel>=LogLevelInfo)
        std::cout << "[INFO]:" << message << std::endl; 
    }
    void Warning(const char* message)
    {   
        if(LogLevel>=LogLevelWarning)
        std::cout << "[WARNING]:" << message << std::endl; 
    }
    void Error(const char* message)
    {
        if(LogLevel>=LogLevelError)
        std::cout << "[ERROR]:" << message << std::endl; 
    }

};


int main()
{
    LOG mylog;
    mylog.SetLevel(mylog.LogLevelInfo);
    mylog.Error("hello world");
    mylog.Warning("just a warning, take it easy!");
    mylog.Info("it a test info.");
    std::cin.get();
}