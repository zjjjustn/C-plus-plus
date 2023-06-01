#include<iostream>

using namespace std;

class Test
{
public:
    Test() = default;
    Test(int t,int num,int count) :m_t(t),m_num(num),m_count(count)
    {

    }
    int m_t;
    int m_num;
    int m_count;

};

int main(int argc,char **argv)
{
    Test t1;
    Test t2(1,2,4);
    Test t3(1,2,5);
}   
