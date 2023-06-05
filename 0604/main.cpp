#include <iostream>
#include "singleton3.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    Singleton *p3 = Singleton::getInstance();

    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    
    return 0;
}