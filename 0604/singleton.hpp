#pragma once
class Singleton
{
public:
    static Singleton * getInstance()
    {
        //lock
        if(p == nullptr)
        {
            p =  new Singleton();
        }
        //unlock
        return p; 
    }
    
    static Singleton *p;

private:
    Singleton()
    {
        
    }
};

Singleton * Singleton::p = nullptr; 