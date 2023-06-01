#include<iostream>
using namespace std;

class Test
{
public:
    void print()
    {
        auto func = [this]()
        {
            cout << m_t << endl;
            cout << m_num << endl;
        };
        func();
    }
    int m_t;
    int m_num;

};

int add(int a,int b)
{
    return a+b;
}

int main(int argc,char **argv)
{
    int num1 = 5;
    int num2 = 6;
    int num3 = 7;
    int result = add(num1,num2);
    cout<<result <<endl;

    /*
    1.简化程序结构（函数命名、函数传参）、提高运行效率（函数执行和返回及空间的分配释放）
    2.能够便捷的使用STL算法

    =:按照值捕获：只能使用不能修改
    &:按照地址捕获：读写
    变量名，变量名，按照值捕获：只能使用不能修改
    &变量名，&变量名，:读写
    副本捕获：自定义变量名 = 捕获变量：C++14


    
    */
    auto func_add = [x = num1,y = num2]()
    {
        // num1 =20;
        // return num1+num2;
        return x+y;
    };
    cout << num1 << endl;
    auto func_add1 =[=](int a ,int b)
    {
        return a+b;
    };
    auto func_add2 = [=]
    {
        return num1+num2;
    };
    cout << func_add() <<endl;
    cout << func_add1(num1,num2) <<endl;
    cout << func_add2() <<endl;

    return 0;
}