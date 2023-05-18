#pragma once
#include <string.h>
#include <vector>

using namespace std;
#define MAX_SIZE 1024

namespace V
{
    namespace V1
    {
        class Stack
        {
            public:
        }

        Stack(const Stack &other)
        {
【
        }
        Stack(Stack &&other)
        {
            cout<<"Stack constructor Move"<<endl;
            this->stack = other.stack;
            other.stack = nullptr;
            this->MAX_SIZE = other.MAX_SIZE;
            this->top = 
        }
    }
}