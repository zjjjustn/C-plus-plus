#include <iostream>
#include "stack.hpp"

using namespace std;

void test_stack()
{
    V::V1::Stack s;
    cout<<sizeof(s)<<endl;
    V::V1::Stack s2(10000);
    V::V1::Stack s3(s2);

    V::V1::Stack s4;
    s4.operator =(s2);

    s3.push(1);
    cout<<s3.get_top()<<endl;
    s3.pop;
}
Test function2()
{
    Test temp("zhangsan",12);
    return temp;
}
void test_ref()
{
    int num =5;
    int &lnum = num;
    const int &clnum =5;
    int &&rnum =5;

    Test("kk",12);
    
}

int main(int argc,char **argv)
{
    //V::V1::Stack s;
    Test t("hello world",11);
    Test t1(t);
    Test t2 = t;

    Test t3;
    t3.operator = (t);

    for(int i=0;i<10000;i++)
    {
        Test result = function2();
    }

}
