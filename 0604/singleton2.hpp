#pragma once
class Singleton
{
public:
    static Singleton * getInstance()
    {
        return p; 
    }
    
    static Singleton *p;

private:
    Singleton()
    {
        
    }
};

Singleton * Singleton::p = new Singleton; 