#pragma once
#include<iostream>
using namespace std;

class Test
{
public:
    Test() = default;
    Test(int t) : m_t(t);
    {

    }
    ~Test()
    {

    }
    void print()
    {
        cout<<m_t<<endl;
    }
    int get_num()
    {
        
    }
    int m_t;
    int m_t2;
    int m_t3;
}