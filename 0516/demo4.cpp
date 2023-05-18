#include<iostream>
using namespace std;

class Test
{
public:
    Test() = default;
    int len;
    //Test(const Test &other)= delete;
private:
    int num;
    // Test(const Test &other)
    // {

    // }
};

int main(int argc,char ** argv)
{
    Test t;
    Test t1(t);
    return 0;

}