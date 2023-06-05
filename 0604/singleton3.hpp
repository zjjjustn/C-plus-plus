#pragma once
class Singleton
{
public:
    static Singleton * getInstance()
    {
        static Singleton p;
        return &p;
    }
    
    static Singleton *p;

private:
    Singleton()
    {
        
    }
};

