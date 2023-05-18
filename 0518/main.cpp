#include<iostream>
#include"A.hpp"
#include"test2.hpp"
using namespace std;

void func3(Test &other)
{
    for(int i = 0;i<100000;i++)
    {
        //cout<<other.get_num()<<endl;
        cout<<other.m_num<<endl;
    }
}
int main(int argc,char **argv)
{
    Test t;
    t.set_num(1000);
    func3(t);
    A a;


}